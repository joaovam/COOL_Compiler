/*
 *  cool.y
 *              Parser definition for the COOL language.
 *
 */
%{
#include <iostream.h>
#include "cool-tree.h"
#include "stringtab.h"
#include "utilities.h"

extern char *curr_filename;

void yyerror(char *s);        /*  defined below; called for each parse error */
extern int yylex();           /*  the entry point to the lexer  */

/************************************************************************/
/*                DONT CHANGE ANYTHING IN THIS SECTION                  */

Program ast_root;	      /* the result of the parse  */
Classes parse_results;        /* for use in semantic analysis */
int omerrs = 0;               /* number of errors in lexing and parsing */
%}

/* A union of all the types that can be the result of parsing actions. */
%union {
  Boolean boolean;
  Symbol symbol;
  Program program;
  Class_ class_;
  Classes classes;
  Feature feature;
  Features features;
  Formal formal;
  Formals formals;
  Case case_;
  Cases cases;
  Expression expression;
  Expressions expressions;
  char *error_msg;
}

/* 
   Declare the terminals; a few have types for associated lexemes.
   The token ERROR is never used in the parser; thus, it is a parse
   error when the lexer returns it.

   The integer following token declaration is the numeric constant used
   to represent that token internally.  Typically, Bison generates these
   on its own, but we give explicit numbers to prevent version parity
   problems (bison 1.25 and earlier start at 258, later versions -- at
   257)
*/
%token CLASS 258 ELSE 259 FI 260 IF 261 IN 262 
%token INHERITS 263 LET 264 LOOP 265 POOL 266 THEN 267 WHILE 268
%token CASE 269 ESAC 270 OF 271 DARROW 272 NEW 273 ISVOID 274
%token <symbol>  STR_CONST 275 INT_CONST 276 
%token <boolean> BOOL_CONST 277
%token <symbol>  TYPEID 278 OBJECTID 279 
%token ASSIGN 280 NOT 281 LE 282 ERROR 283

/*  DON'T CHANGE ANYTHING ABOVE THIS LINE, OR YOUR PARSER WONT WORK       */
/**************************************************************************/
 
   /* Complete the nonterminal list below, giving a type for the semantic
      value of each non terminal. (See section 3.6 in the bison 
      documentation for details). */

/* Declare types for the grammar's non-terminals. */
%type <program> program
%type <classes> class_list
%type <class_> class

/* You will want to change the following line. */
%type <features> feature_list
%type <features> nonempty_feature_list
%type <feature> feature

%type <formals> formal_list
%type <formals> nonempty_formal_list    
%type <formal> declaration

%type <expressions> expression_list nonempty_expression_list
%type <expressions> expression_semicolon_list
%type <expression> expression
/* %type <cases> case_list
%type <case_> case_
%type <expression> let_list */

/* Precedence declarations go here. */
%left '.'
%left '@'
%left '~'
%left ISVOID
%left '*'
%left '/'
%left '+'
%left '-'
%left NOT

%left LET

%right ASSIGN

%nonassoc LE '=' '<'



%%
/* 
   Save the root of the abstract syntax tree in a global variable.
*/
program	: class_list	{ ast_root = program($1); }
        ;

class_list
	: class			/* single class */
		{ $$ = single_Classes($1);
                  parse_results = $$; }
	| class_list class	/* several classes */
		{ $$ = append_Classes($1,single_Classes($2)); 
                  parse_results = $$; }
	;

/* If no parent is specified, the class inherits from the Object class. */
class	: CLASS TYPEID '{' feature_list '}' ';'
		{ $$ = class_($2,idtable.add_string("Object"),$4,
			      stringtable.add_string(curr_filename)); }
	| CLASS TYPEID INHERITS TYPEID '{' feature_list '}' ';'
		{ $$ = class_($2,$4,$6,stringtable.add_string(curr_filename)); }
	;

/* Feature list may be empty, but no empty features in list. */
feature_list:		
    /* empty */
    {  $$ = nil_Features(); }
| nonempty_feature_list {}


nonempty_feature_list:
    feature {$$ = nil_Features();}

| nonempty_feature_list feature {$$ = append_Features($1, single_Features($2));}

feature:
OBJECTID '(' formal_list ')' ':' TYPEID '{' expression '}' ';'
  {$$ = method($1, $3, $6, $8);}

| OBJECTID ':' TYPEID ';'
  {$$ = attr($1,$3, no_expr());}

| OBJECTID ':' TYPEID ASSIGN expression ';'
  {$$ = attr($1, $3, $5);}

| error ';'
  {$$ = $$;};



formal_list:
  {$$ = nil_formals();}
| nonempty_formal_list
  {}


nonempty_formal_list:
declaration
    {$$ = single_Formals($1);}
| formal_list ',' declaration
    {$$ = append_Formals($1, single_Formals($3));}


declaration :
    OBJECTID ':' TYPEID
    {$$ = formal($1, $3);}

  
expression_list:
  {$$ = nil_Expressions();}
| nonempty_expression_list
  {$$ = Expression()}

nonempty_expression_list:
  expression 
  {$$ = single_Expressions($1);}
| nonempty_expression_list ',' expression 
  {$$ = append_Expressions($1, single_Expressions($3));}

expression_semicolon_list:
expression
 {$$ = single_Expressions($1);}

| expression_semicolon_list ';' expression
{$$ = append_Expressions($1, single_Expressions($3));}

expression: //assignment, function call, while, if, expression blocks
 OBJECTID ASSIGN expression
  {$$ = assign($1,$3);}
| expression '.' OBJECTID '(' expression_list ')'
  {$$ = dispatch($1, $3, $5);}

| WHILE expression LOOP expression POOL
  {$$ = loop($2, $4);}

| IF expression THEN expression ELSE expression FI
  {$$ = cond($2, $4, $6);}

| '{' expression_semicolon_list ';'
  {$$ = block($2);}

| '{' expression_semicolon_list ';' error ';'
  {$$ = $$;}

| '{' expression_semicolon_list ';' error ';' expression_semicolon_list ';'
  {$$ = $$;}

| error ';' expression_semicolon_list ';'
  {$$ = $$;}


/* end of grammar */
%%

/* This function is called automatically when Bison detects a parse error. */
void yyerror(char *s)
{
  extern int curr_lineno;

  cerr << "\"" << curr_filename << "\", line " << curr_lineno << ": " \
    << s << " at or near ";
  print_cool_token(yychar);
  cerr << endl;
  omerrs++;

  if(omerrs>50) {fprintf(stdout, "More than 50 errors\n"); exit(1);}
}


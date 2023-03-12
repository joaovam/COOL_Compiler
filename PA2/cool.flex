/*
 *  The scanner definition for COOL.
 */

/*
 *  Stuff enclosed in %{ %} in the first section is copied verbatim to the
 *  output, so headers and global definitions are placed here to be visible
 * to the code in the file.  Dont remove anything that was here initially
 */
%{
#include <cool-parse.h>
#include <stringtab.h>
#include <utilities.h>

/* The compiler assumes these identifiers. */
#define yylval cool_yylval
#define yylex  cool_yylex

/* Max size of string constants */
#define MAX_STR_CONST 1025
#define YY_NO_UNPUT   /* keep g++ happy */

int string_const_size = 0;
int nested = 0;

extern FILE *fin; /* we read from this file */

/* define YY_INPUT so we read from the FILE fin:
 * This change makes it possible to use this scanner in
 * the Cool compiler.
 */
#undef YY_INPUT
#define YY_INPUT(buf,result,max_size) \
	if ( (result = fread( (char*)buf, sizeof(char), max_size, fin)) < 0) \
		YY_FATAL_ERROR( "read() in flex scanner failed");

char string_buf[MAX_STR_CONST]; /* to assemble string constants */

extern int curr_lineno;
extern int verbose_flag;

extern YYSTYPE cool_yylval;

/*
 *  Add Your own definitions here
 */

%}
int curr_lineno = 0;
%x cmt_1 
%x cmt_2
%x string_constant
%x skip_str
%x count_line


/*
 * Define names for regular expressions here.
 */

DIGIT [0-9]
LOWERCASE_LETTER [a-z]
UPPERCASE_LETTER [A-Z]
WHITE_SPACE [\r\t\v\f ]

a [aA]
b [bB]
c [cC]
d [dD]
e [eE]
f [fF]
g [gG]
h [hH]
i [iI]
j [jJ]
k [kK]
l [lL]
m [mM]
n [nN]
o [oO]
p [pP]
q [qQ]
r [rR]
s [sS]
t [tT]
u [uU]
v [vV]
w [wW]
x [xX]
y [yY]
z [zZ]

DARROW =>
LARROW <=   
ASSIGNMENT <-

%%

 /*
  *  Nested comments
  */


 /*
  *  The multiple-character operators.

  */

 //comment and endline section
[\n] {curr_lineno++;}

"--" {BEGIN(cmt_1);}
"(*" {BEGIN(cmt_2);nested = 1;}
"*)" {cool_yylval.error_msg ="Unmatched *)"; return ERROR;}

<cmt_1>[\n] {curr_lineno++;BEGIN(0);}
<cmt_1><<EOF>> {cool_yylval.error_msg = "EOF in comment";BEGIN(0); return ERROR;}
<cmt_1>. {;}

<cmt_2><<EOF>> {cool_yylval.error_msg = "EOF in comment";BEGIN(0); return ERROR;}

<cmt_2>[\n] {curr_lineno++;} 
<cmt_2>"(*" {nested++;}

<cmt_2>"*)" {
      nested--;
      
      if(nested == 0)
            BEGIN(0);
            
      }

<cmt_2>. {;}

\" {BEGIN(string_constant); string_const_size = 0; memset(string_buf, '\0', MAX_STR_CONST);}

 /*usado para quebra de linha com "/" de escape*/

<string_constant>\\\n { curr_lineno++; string_const_size++;}
<string_constant>\n {cool_yylval.error_msg="Unterminated string constant"; curr_lineno++; BEGIN(skip_str);return ERROR; }

<string_constant>\0 {cool_yylval.error_msg="String contains null characters"; BEGIN(0); return ERROR;}
<string_constant><<EOF>> {cool_yylval.error_msg = "EOF in String"; BEGIN(0); return ERROR;}

<skip_str>\" {BEGIN(0);}
<skip_str>\n {curr_lineno++;}
<skip_str>. {}


<string_constant>\\[0] {strcat(string_buf,"0"); string_const_size++;}
<string_constant>\\[n] {strcat(string_buf,"\n"); string_const_size++;}
<string_constant>\\[t] {strcat(string_buf,"\t"); string_const_size++;}
<string_constant>\\[b] {strcat(string_buf,"\b"); string_const_size++;}
<string_constant>\\[f] {strcat(string_buf,"\f"); string_const_size++;}
<string_constant>\\. {strcat(string_buf, &yytext[1]);string_const_size++;}

<string_constant>[^\n\"] { 
      if(string_const_size < MAX_STR_CONST){
            strcat(string_buf, yytext); string_const_size++;
      }else{
            cool_yylval.error_msg = "String constant too long";
            BEGIN(skip_str);
            return ERROR;
      }
}



<string_constant>\" {
      if(string_const_size > MAX_STR_CONST - 1){
            cool_yylval.error_msg = "String constant too long";
            BEGIN(skip_str);
            return ERROR;
      }else{
            cool_yylval.symbol = stringtable.add_string(string_buf);
            BEGIN(0);
            return STR_CONST;
      }
}
      


{DIGIT}+ { /*number*/
      cool_yylval.symbol = inttable.add_string(yytext);
      return INT_CONST;
}
{WHITE_SPACE}+ {}


{i}{f} {return IF;}
{t}{h}{e}{n} {return THEN;}
{e}{l}{s}{e} {return ELSE;}
{f}{i} {return FI;}

{c}{l}{a}{s}{s} {return CLASS;}
{i}{n}{h}{e}{r}{i}{t}{s} {return INHERITS;}
{n}{e}{w} {return NEW;}

{l}{e}{t} {return LET;}
{i}{n} {return IN;}

{c}{a}{s}{e} {return CASE;}
{e}{s}{a}{c} {return ESAC;}

{w}{h}{i}{l}{e} {return WHILE;}
{l}{o}{o}{p} {return LOOP;}
{p}{o}{o}{l} {return POOL;}

{o}{f} {return OF;}
{n}{o}{t} {return NOT;}
{i}{s}{v}{o}{i}{d} {return ISVOID;}



t{r}{u}{e} {cool_yylval.boolean = true; return BOOL_CONST;}
f{a}{l}{s}{e} {cool_yylval.boolean = false; return BOOL_CONST;}


[a-z][_a-zA-Z0-9]* {/*object id*/
      cool_yylval.symbol = idtable.add_string(yytext);
      return OBJECTID;
}

[A-Z][_a-zA-Z0-9]* {/*type id*/
      cool_yylval.symbol = idtable.add_string(yytext);
      return TYPEID;
}


{ASSIGNMENT} {return ASSIGN;}


 /*operators*/
"." {return '.';}
"@" {return '@';}
"~" {return '~';}
"*" {return '*';}
"/" {return '/';}
"+" {return '+';}
"-" {return '-';}
"<" {return '<';}
"=" {return '=';}

"{" {return '{';}
"}" {return '}';}
";" {return ';';}
"(" {return '(';}
")" {return ')';}
":" {return ':';}
"," {return ',';}





{DARROW}		{ return (DARROW); }

. {
cool_yylval.error_msg = yytext;
return ERROR;
}//armazena erro que possa ter chegado ao final do lexer








 /*
  * Keywords are case-insensitive except for the values true and false,
  * which must begin with a lower-case letter.
  */


 /*
  *  String constants (C syntax)
  *  Escape sequence \c is accepted for all characters c. Except for 
  *  \n \t \b \f, the result is c.
  *
  */


%%

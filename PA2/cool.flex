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
char *string_buf_ptr;

extern int curr_lineno;
extern int verbose_flag;

extern YYSTYPE cool_yylval;

/*
 *  Add Your own definitions here
 */

%}
int curr_lineno = 0;

/*
 * Define names for regular expressions here.
 */

DIGIT [0-9]
LOWERCASE_LETTER [a-z]
UPPERCASE_LETTER [A-Z]
WHITE_SPACE [\n\r\t\v\f ]

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
r [rR]
s [sS]
t [tT]
u [uU]
v [vV]
w [wW]
x [xX]
y [yY]
z [zZ]

DARROW          =>

%%

 /*
  *  Nested comments
  */


 /*
  *  The multiple-character operators.

  */

{DIGIT}+ { 
      cool_yylval.symbol = inttable.add_string(yytext);
      return INT_CONST;
    }

[a-z][_a-zA-Z0-9]* {
      cool_yylval.symbol = idtable.add_string(yytext);
      return OBJECTID;
}


{WHITE_SPACE}+ {}


{i}{f} {return IF;}
{t}{h}{e}{n} {return THEN;}
{f}{i} {return FI;}
{e}{l}{s}{e} {return ELSE;}

t{r}{u}{e} {cool_yylval.boolean = true; return BOOL_CONST;}
 . {
    cool_yylval.error_msg = yytext;
    return ERROR;
}//armazena erro que possa ter chegado ao final do lexer


{DARROW}		{ return (DARROW); }

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

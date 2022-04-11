%{
#include<stdio.h>
%}
assg =
aop [+-/*%]
rop (>|<|">="|"<="|"=="|"!=")
bop [&^~|"|"]
lop (!|&&|"||")
shift ("<<"|">>")
inc ("++")
dec ("--")
other [a-zA-Z0-9_@#$.?;]
%%
{assg} {printf("\n %s is an Assignment operator!",yytext);}
{aop} {printf("\n %s is an Arithmetic operator !",yytext);}
{rop} {printf("\n %s is a Relational operator!",yytext);}
{bop} {printf("\n %s is a Bitwise operator!",yytext);}
{lop} {printf("\n %s is a Logical operator!",yytext);}
{shift} {printf("\n %s is a Shift operator!",yytext);}

{inc} {printf("\n %s is an Increment operator!",yytext);}
{dec} {printf("\n  %s is a Decrement operator!",yytext);}
{other} {printf("\n	%s is not an operator !",yytext);}
%%
int yywrap() { }
int main()
{
printf(" enter any operator ");
yylex();
}

%{
#include<stdio.h>
int posint=0;
int posneg=0;
int posfrac=0;
int negfrac=0;
%}
%%
[+]?[0-9]+ { posint++;}
[-][0-9]+ { posneg++;}
[+]?[0-9]+\.[0-9]* { posfrac++; }
[-][0-9]+\.[0-9]* { negfrac++; }
%%
int yywrap(){}
int main(int argc, char* argv[])
{
yyin = fopen(argv[1],"r");
yylex();
printf(" number of positive integers  are %d\n", posint);
printf(" number of negative integers  are %d\n", posneg);
printf(" number of positive fractions are %d\n", posfrac);
printf(" number of negative fractions are %d\n", negfrac);
return 0;
}

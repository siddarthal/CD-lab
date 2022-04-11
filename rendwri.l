%{
#include<stdio.h>
int pcount=0,scount=0;
%}

%%
"printf" {fprintf(yyout,"writef");pcount++;}
"scanf" {fprintf(yyout,"readf");scount++;}
%%
int yywrap(){}
int main(int argc, char* argv[])
{

yyin=fopen(argv[1],"r");
yyout=fopen(argv[2],"w");

yylex();
printf(" no of printfs are %d ", pcount);
printf(" no of scanf are % d", scount);
}

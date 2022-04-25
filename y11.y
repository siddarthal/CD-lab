%{
#include<stdio.h>
#include<stdlib.h>
int yylex(void);
int yyerror();
%}
%token A B  NL 
%%
start: S NL {printf("valid string\n");  exit(0); };
S: A S B
| ;
%%
int main()
{
 	printf("enter string");
	yyparse();
        return 0;	
}
int yyerror(char *s)
{
   printf("not accepted");
    exit(0);
}


   %{
    #include<stdio.h>
    #include<stdlib.h>
    int a=0,b=0,c=0,d;
%}
%%
"//".* {a++;}
"/*" {b++;}
.*"*/" {b--;c++;}
%%
void main(int argc,char *argv[]){
    yyin=fopen(argv[1],"r");
    yylex();
    printf("single line %d \nmultiline %d \n",a,c);
    d=a+c;
    printf("total %d \n",d);
}

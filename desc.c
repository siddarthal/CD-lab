#include<stdio.h>
char input[15];
int ip=0;
int S();
int A();
int S()
{
if(input[ip]=='c')
{
ip++;
if(A())
{
if(input[ip]=='d')
{
ip++;
return 1;
}
}
}
return 0;
}
int A()
{
int isave=ip;
if(input[ip]=='a')
{
ip++;
if(input[ip]=='b')
{
ip++;
return 1;
}
}
ip=isave;
if(input[ip]=='a')
{
ip++;
return 1;
}
else
return 0;
}
int main()
{
int flag;
printf("Enter the input of the grammar S->cAd, A->ab/a ending with $");
scanf("%s",input);
flag=S();
if(flag==1 && input[ip]=='$')
{
printf("valid input");
}
else
printf("invalid input");
return 0;
}

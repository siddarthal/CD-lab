#include <stdio.h>
#include<string.h>
#include<stdlib.h>
char input[20];
int top = -1;
char stk[20];
int ip=0;
void main()
{
int flag=0;
printf("\nEnter the input to be parsed with the delimiter $");
scanf("%s",input);
push('$');
push('E');
printf("STACK                                     INPUTDATA");
while(1)
{
printf("\n");
display();
printf(" ------------------------------------- ");
inputdisplay();
if(stk[top]=='$'&&input[ip]=='$')
{
flag=1;
printf("\nSuccessfully parsed");
break;
}
else if(stk[top]==input[ip]) 
{
ip++;
pop(); 
}

else if(stk[top]=='E') 
{
if(input[ip]=='i'|| '(') 
{
pop();
push('A');
push('T');
 }
else
break;
}
else if(stk[top]=='A') 
{
if(input[ip]=='+') 
{
pop();
push('A');
push('T');
push('+');
 }
else if(input[ip]==')'||'$') 
{
pop(); 
}
else
break;
}
else if(stk[top]=='T') 
{
if(input[ip]=='i'||'(') 
{
pop();
push('B');
push('F'); 
}
else
break;
}
else if(stk[top]=='B') 
{
if(input[ip]=='*') 
{
pop();
push('B');
push('F');
push('*');
}
else if(input[ip]=='+'||')'||'$') 
{
pop();
 }
else
break;
}
else if(stk[top]=='F') 
{
if(input[ip]=='i') 
{
pop();
push('i'); 
}
else if(input[ip]=='(')
 {
pop();
push(')');
push('E');
push('('); 
}
else
break;
}
else
break;
}
if(flag==0)
	printf("\nIt is an invalid input");
}
void push(char t)
{

if(top>=20)
printf("stack overflow");
else
stk[++top]=t;
}
void pop(){

if(top==-1)
printf("stack underflow");
else
top--;
}
void display()
{
int i;
for(i=0;i<=top;i++)
printf("%c",stk[i]);
}
void inputdisplay()
{
int i;
i=ip;
while(input[i]!='\0')
printf("%c",input[i++]);
}



























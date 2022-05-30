#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void push(char);
void pop();
char input[10];
char stk[20];
int top=-1;
int ip=0;
void push(char c)
{
    	if(top>=20)
		printf("stack overflow");
	else
		stk[++top]=c;
}
void pop()
{
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
void main()
{
int flag=0;
printf("\nEnter the input to be parsed with the delimiter $");
scanf("%s",input);
push('$');
push('A');
printf("STACK                                               INPUTDATA");
while(1)
{
	printf("\n");
	display();
	printf(" ------------------------------------- ");
	inputdisplay();
	if(stk[top]=='$'&&input[ip]=='$')
	{
		flag=1;
		printf("\nSuccessful parser");
		break;
	}
	else if(stk[top]==input[ip]) 
	{
		ip++;
		pop(); 
	}
	else if(stk[top]=='A') 
	{
		if(input[ip]=='a') 
 		{
			pop();
			push('a');
			push('B');
			push('a');
		 }
		else
			break;
	}
	else if(stk[top]=='B') 
	{
		if(input[ip]=='b') 
		{
			pop();
			push('B');
			push('b');
			
		 }
		else if(input[ip]=='a') 
		{
			pop(); 
		}
		else
			break;
	}


		break;

}
if(flag==0)
	printf("\nIt is an invalid input");
}

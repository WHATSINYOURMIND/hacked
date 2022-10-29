#include<stdio.h>
#include<string.h>
#define N 20
typedef struct stack
{
	char a[N];
	int top;
}stack;

void push(stack *s,char x)
{
	s->top++;
	s->a[s->top]=x;
}

char pop(stack *s)
{
	char x;
	x=s->a[s->top];
	s->top--;
	return x;
}

int isempty(stack *s)
{
	if(s->top==-1)
		return 1;
	else
		return 0;
}

char stacktop(stack *s)
{
	return s->a[s->top];
}

int isoperand(char x)
{
	if((x>='A'&&x<='Z')||(x>='a'&&x<='z'))
		return 1;
	else
		return 0;
}

int isoperator(char x)
{
	if(x=='+'||x=='-'||x=='*'||x=='/')
		return 1;
	else
		return 0;
}

int priority(char x)
{
	if(x=='*'||x=='/')
		return 3;
	else if(x=='+'||x=='-')
		return 2;
	else
		return 1;
}

void convert(char infix[],char postfix[])
{
	stack s;
	s.top=-1;
	int i,k=0;
	char x,ele;
	for(i=0;i<strlen(infix);i++)
	{
		x=infix[i];
		if(isoperand(x))
			postfix[k++]=x;
		else if(x=='(')
			push(&s,x);
		else if(isoperator(x))
		{
			while(priority(x)<=priority(stacktop(&s)))
			{
				ele=pop(&s);
				postfix[k++]=ele;
			}
			push(&s,x);
		}
		else
		{
			while(stacktop(&s)!='(')
			{
				ele=pop(&s);
				postfix[k++]=ele;
			}
			ele=pop(&s);
		}	
	}
	while(isempty(&s)==0)
	{
		ele=pop(&s);
		postfix[k++]=ele;
	}
	postfix[k]='\0';
}

int main()
{
	char infix[20],postfix[20];
	printf("Enter infix expression=");
	gets(infix);
	convert(infix,postfix);
	printf("\nPostfix Expression=%s",postfix);
	return 0;
}


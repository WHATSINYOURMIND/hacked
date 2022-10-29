#include<stdio.h>
#include<string.h>
#define N 15
typedef struct stack
{
	int a[N];
	int top;
}stack;

void push(stack *s,int x)
{
	s->top++;
	s->a[s->top]=x;
}

int pop(stack *s)
{
	int x;
	x=s->a[s->top];
	s->top--;
	return x;
}

int isoperand(char x)
{
	if(x>='0'&&x<='9')
		return 1;
	else
		return 0;
}

int evaluate(char postfix[])
{
	stack s;
	s.top=-1;
	int op1,op2,x,v,i;
	for(i=0;i<strlen(postfix);i++)
	{
		x=postfix[i];
		if(isoperand(x))
		{
			push(&s,(int)x-'0');
		}
		else//jab x operator rahega
		{
			op1=pop(&s);
			op2=pop(&s);
			if(x=='+')
			{
				v=op2+op1;
			}
			else if(x=='-')
			{
				v=op2-op1;
			}
			else if(x=='*')
			{
				v=op2*op1;
			}	
			else
			{
				v=op2/op1;
			}
			push(&s,v);
		}
	}
	return pop(&s);
}
int main()
{
	char postfix[10];
	int z;
	printf("Enter postfix expression=");
	gets(postfix);
	z=evaluate(postfix);
	printf("\nResult=%d",z);
	return 0;
}


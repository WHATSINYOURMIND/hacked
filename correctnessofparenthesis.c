#include<stdio.h>
#include<string.h>
#define N 20
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

int isopenbracket(int x)
{
	if(x=='{'||x=='['||x=='(')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isclosebracket(int x)
{
	if(x=='}'||x==']'||x==')')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isempty(stack *s)
{
	if(s->top==-1)
		return 1;
	else
		return 0;
}

int checkkaro(char s1[])
{
	int i,x,ele;
	stack s;
	s.top=-1;
	for(i=0;i<strlen(s1);i++)
	{
		x=s1[i];
		if(isopenbracket(x))
			push(&s,x);
		if(isclosebracket(x))
		{
			if(isempty(&s))
				return 0;
			else
			{
				ele=pop(&s);
				if(x=='}'&&ele!='{')
					return 0;
				if(x==']'&&ele!='[')
					return 0;
				if(x==')'&&ele!='(')
					return 0;	
			}
		}
	}
	if(isempty(&s))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	char s1[20];
	printf("Enter Expression=");
	gets(s1);
	if(checkkaro(s1))
	{
		printf("\nExpression is valid...");
	}
	else
	{
		printf("\nExpression is invalid...");
	}
	return 0;
}


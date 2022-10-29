#include<stdio.h>
#define N 20
typedef struct stack
{
	int a[N];
	int top;
}stack;

void push(stack *s,int x)
{
	if(s->top==N-1)
		printf("\nStack Overflow...");
	else
	{
		s->top=s->top+1;
		s->a[s->top]=x;
	}
}

int isempty(stack *s)
{
	if(s->top==-1)
		return 1;
	else
		return 0;
}

int pop(stack *s)
{
	int x;
	if(isempty(s))
	{
		return -1;
	}
	else
	{
		x=s->a[s->top];
		s->top=s->top-1;
		return x;
	}
}

int peek(stack *s)
{
	if(isempty(s))
		return -1;
	else
		return s->a[s->top];
}

void display(stack *s)
{
	int i;
	if(isempty(s))
	{
		printf("\nStack is empty...");
	}
	else
	{
		for(i=s->top;i>=0;i--)
		{
			printf("\t%d",s->a[i]);
		}
	}
}

int main()
{
	int ch,x;
	stack s;
	s.top=-1;
	while(1)
	{
		printf("\n1:Push\n2:Pop\n3:Peek\n4:Display\n5:Exit\nEnter choice=");
		scanf("%d",&ch);
		if(ch==5)
		break;
		switch(ch)
		{
			case 1:
				{
					printf("\nEnter element to be pushed=");
					scanf("%d",&x);
					push(&s,x);
				}
				break;
			case 2:
				{
					x=pop(&s);
					if(x==-1)
						printf("\nStack Underflow...");
					else
						printf("\nPopped Element=%d",x);
				}
				break;
			case 3:
				{
					x=peek(&s);
					if(x==-1)
						printf("\nStack is empty...");
					else
						printf("\nStack top element=%d",x);
				}
				break;
			case 4:
				{
					display(&s);
				}
				break;
			default:
				{
					printf("\nInvalid Choice...");
				}
		}
	}
	return 0;
}
			

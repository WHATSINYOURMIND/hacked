#include<stdio.h>
#define N 10
typedef struct queue
{
	int a[N];
	int front,rear;
}queue;

void insertleft(queue *q,int x)
{
	if(q->front==-1)
	{
		printf("\nQueue overflow");
	}
	else
	{
		q->a[q->front]=x;
    	q->front--;
	}
}

void insertright(queue *q,int x)
{
	if(q->rear==N-1)
	{
		printf("\nQueue overflow");
    }
    else
    {
    	q->rear++;
    	q->a[q->rear]=x;
	}
}

int isempty(queue *q) 
{
	if(q->front==q->rear)
		return 1;
	else
		return 0;
}

int deleteleft(queue *q)
{
	int x;
	if(isempty(q))
	{
		return -1;
	}
	else
	{
		q->front++;
		x=q->a[q->front];
		return x;
	}	
}

int deleteright(queue *q)
{
	int x;
	if(isempty(q))
	{
		return -1;
	}
	else
	{
		x=q->a[q->rear];
		q->rear--;
		return x;
	}	
}

void display(queue *q)
{
	int i;
	if(isempty(q))
	{
	printf("\nQueue is empty");
    }
    else
    {
    	for(i=q->front+1;i<=q->rear;i++)
    	{
    		printf("\n%d",q->a[i]);
		}
	}
}

int main()
{
	int ch,x;
	queue q;
	q.front=N/2;
	q.rear=N/2;
	while(1)
	{
		printf("\nMenu:\n1:Insert Left\n2:Insert Right\n3:Delete Left\n4:Delete Right\n5:Display\n6:EXIT\nEnter Choice=");
		scanf("%d",&ch);
		if(ch==6)
		break;
		switch(ch)
		{
			case 1:
			{
				printf("\nEnter element to be inserted=");
			    scanf("%d",&x);
			    insertleft(&q,x);
			}
			break;
		    case 2:
			{
				printf("\nEnter element to be inserted=");
			    scanf("%d",&x);
			    insertright(&q,x);
			}
			break;
			case 3: 
			{
				x=deleteleft(&q);
			    if(x==-1)
					printf("\nQueue underflow");
				else
					printf("\nElement deleted=%d",x);
			}
			break;
			case 4: 
			{
				x=deleteright(&q);
			    if(x==-1)
					printf("\nQueue underflow");
				else
					printf("\nElement deleted=%d",x);
			}
			break;
			case 5: 
			{
				display(&q);
			}
			break;
			default:
			{
				printf("\nInvalid choice\n");    
			}  
		}
	}
return 0;
}

#include<stdio.h>
#define N 10
typedef struct queue
{
	int a[N];
	int front,rear;
}queue;

void enqueue(queue *q,int x)
{
	int i,j;
	if(q->rear==N-1)
	{
		printf("\nQueue Overflow");
	}
	else
	{
		for(i=q->front;i<=q->rear;i++)// x ka index find kar ne k liye
		{
			if(x>q->a[i])
				break;
		}
		for(j=q->rear;j>=i;j--)//shifting
		{
			q->a[j+1]=q->a[j];
		}
		q->a[i]=x;
		q->rear++;
	}
}

int isempty(queue *q)
{
	if(q->front==q->rear+1)
		return 1;
	else
		return 0;
}

int dequeue(queue *q)
{
	int x;
	if(isempty(q))
		return -1;
	else
	{
		x=q->a[q->front];
		q->front++;
		return x;
	}
}

void display(queue *q)
{
	int i;
	if(isempty(q))
	{
		printf("\nQueue is empty...");
	}
	else
	{
		for(i=q->front;i<=q->rear;i++)
		{
			printf("\n%d",q->a[i]);
		}
	}
}

int main()
{
	int ch,x;
	queue q;
	q.front=0;
	q.rear=-1;
	while(1)
	{
		printf("\nMenu:\n1-ENQUEUE\n2-DEQUEUE\n3-DISPLAY\n4-EXIT\nEnter Choice=");
		scanf("%d",&ch);
		if(ch==4)
			break;
		switch(ch)
		{
			case 1:
				{
					printf("\nEnter element to be inserted=");
					scanf("%d",&x);
					enqueue(&q,x);
				}
				break;
			case 2:
				{
					x=dequeue(&q);
					if(x==-1)
					{
						printf("\nQueue Underflow...");
					}
					else
					{
						printf("\nDeleted Element=%d",x);
					}
				}
				break;
			case 3:
				{
					display(&q);
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

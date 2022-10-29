#include<stdio.h>
#define N 5
typedef struct queue
{
	int a[N];
	int front,rear,count;
}queue;

void enqueue(queue *q, int x)
{
	if(q->count==N)
		printf("\nQueue Overflow...");
	else
	{
		q->count++;
		q->rear=(q->rear+1)%N;
		q->a[q->rear]=x;
	}
}

int isempty(queue *q)
{
	if(q->count==0)
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
		q->count--;
		x=q->a[q->front];
		q->front=(q->front+1)%N;
		return x;
	}
}

void display(queue *q)
{
	int i;
	if(isempty(q))
	{
		printf("\nQueue is empty..");
	}
	else
	{
		i=q->front;
		while(1)
		{
			printf("\n%d",q->a[i]);
			if(i==q->rear)
				break;
			else
				i=(i+1)%N;
		}
	}
}

int main()
{
	int ch,x;
	queue q;
	q.front=0;
	q.rear=-1;
	q.count=0;
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

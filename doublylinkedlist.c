#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next,*prev;
}node;

typedef struct LL
{
	node *start;
}LL;

void insertbegin(LL *l,int x)
{
	node *newrec;
	newrec=(node*)malloc(sizeof(node));
	newrec->data=x;
	newrec->next=NULL;
	newrec->prev=NULL;
	if(l->start==NULL)
	{
		l->start=newrec;
	}
	else
	{
		newrec->next=l->start;
		l->start->prev=newrec;
		l->start=newrec;
	}			
}

void insertend(LL *l,int x)
{
	node *newrec,*p;
	newrec=(node*)malloc(sizeof(node));
	newrec->data=x;
	newrec->next=NULL;
	newrec->prev=NULL;
	if(l->start==NULL)
	{
		l->start=newrec;
	}
	else
	{
		p=l->start;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=newrec;
		newrec->prev=p;
	}	
}

void deletebegin(LL *l)
{
	node *p;
	if(l->start==NULL)
	{
		printf("\nDeletion not possible...");
	}
	else
	{
		p=l->start;
		l->start=l->start->next;
		l->start->prev=NULL;
		free(p);
	}
}

void deleteend(LL *l)
{
	node *p,*q;
	if(l->start==NULL)
	{
		printf("\nDeletion not possible...");
	}
	else if(l->start->next==NULL)//only 1 node
	{
		p=l->start;
		l->start=NULL;
		free(p);
	}
	else
	{
		q=l->start;
		while(q->next->next!=NULL)
		{
			q=q->next;
		}
		p=q->next;
		q->next=NULL;
		p->prev=NULL;
		free(p);
	}
}

void display(LL *l)
{
	int c;
	node *p;
	if(l->start==NULL)
	{
		printf("\nList is empty...");
	}
	else
	{
	printf("\n1-Forward Direction\n2-Backword Direction\nEnter Choice=");
	scanf("%d",&c);
	if(c==1)
	{
		p=l->start;
		while(p!=NULL)
		{
			printf("\n%d",p->data);
			p=p->next;
		}
	}
	else if(c==2)
	{
		p=l->start;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		while(p!=NULL)
		{
			printf("\n%d",p->data);
			p=p->prev;
		}
	}
	else
	{
		printf("\nInvalid Choice...");
	}
}
}

int main()
{
	int ch,x;
	LL l;
	l.start=NULL;
	while(1)
	{
		printf("\nMenu:\n1-Insert at beginning\n2-Insert at end\n3-Delete at beginning\n4-Delete at end\n5-Display\n6-EXIT\nEnter Choice=");
		scanf("%d",&ch);
		if(ch==6)
			break;
		switch(ch)
		{
			case 1:
				{
					printf("\nEnter element to be inserted=");
					scanf("%d",&x);
					insertbegin(&l,x);
					display(&l);
				}
				break;
			case 2:
				{
					printf("\nEnter element to be inserted=");
					scanf("%d",&x);
					insertend(&l,x);
					display(&l);
				}
				break;
			case 3:
				{
					deletebegin(&l);
					display(&l);
				}
				break;
			case 4:
				{
					deleteend(&l);
					display(&l);
				}
				break;
			case 5:
				{
					display(&l);
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

















#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int c,e;
	struct node *next;
}node;

typedef struct LL
{
	node *start;
}LL;

void insertend(LL *l,int cc,int ee)
{
	node *newrec,*p;
	newrec=(node*)malloc(sizeof(node));
	newrec->c=cc;
	newrec->e=ee;
	newrec->next=NULL;
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
	}
}

void display(LL *l)
{
	node *p;
	if(l->start==NULL)
	{
		printf("\nList is empty...");
	}
	else
	{
		p=l->start;
		while(p!=NULL)
		{
			printf("\t%d,%d",p->c,p->e);
			p=p->next;
		}
	}
}

void accept(LL *l)
{
	int n,i,cc,ee;
	printf("\nEnter number of terms=");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter coefficient and exponent=");
		scanf("%d%d",&cc,&ee);
		insertend(l,cc,ee);
	}
}

void add(LL *l1,LL *l2,LL *l3)
{
	node *p,*q;
	p=l1->start;
	q=l2->start;
	while(p!=NULL&&q!=NULL)
	{
		if(p->e>q->e)
		{
			insertend(l3,p->c,p->e);
			p=p->next;
		}
		else if(p->e<q->e)
		{
			insertend(l3,q->c,q->e);
			q=q->next;
		}
		else
		{
			insertend(l3,p->c+q->c,p->e);
			p=p->next;
			q=q->next;
		}
	}
	
	while(p!=NULL)
	{
		insertend(l3,p->c,p->e);
		p=p->next;
	}
	
	while(q!=NULL)
	{
		insertend(l3,q->c,q->e);
		q=q->next;
	}
}

int main()
{
	LL l1,l2,l3;
	l1.start=l2.start=l3.start=NULL;
	accept(&l1);
	display(&l1);
	accept(&l2);
	display(&l2);
	add(&l1,&l2,&l3);
	printf("\nAddition=\n");
	display(&l3);
	return 0;
}

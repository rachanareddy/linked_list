// merge.c.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void display(struct node *);
void merge(struct node *,struct node *);
 struct node *head,*temp;
void main()
{
	struct node *ahead,*temp,*x,*y,*bhead;
	int n,num1,num2,m;
	
	printf("list 1\n");
    ahead=NULL;
    printf("enter a number of elements");
	scanf("%d",&n);
	while(n>0)
	{
		printf("enter number ");
		scanf("%d",&num1);
		temp=(struct node *)malloc(sizeof(struct node));
		temp->data=num1;
		temp->next=NULL;
		if(ahead==NULL)
		{
		ahead=temp;
		x=ahead;
		}
		else
		{
			x->next=temp;
			x=temp;
		}
		n--;
	}
	display(ahead);
	printf("\nlist2\n");
    	bhead=NULL;
    printf("enter a number of elements");
	scanf("%d",&m);
	while(m>0)
	{
		printf("enter number ");
		scanf("%d",&num2);
		temp=(struct node *)malloc(sizeof(struct node));
		temp->data=num2;
		temp->next=NULL;
		if(bhead==NULL)
		{
		bhead=temp;
		y=bhead;
		}
		else
		{
			y->next=temp;
			y=temp;
		}
		m--;
	}
	display(bhead);
	printf(" \n merged list\n");
	merge(ahead,bhead);
	getch();
	return;
}
void display(struct node *p)
{
	while(p!=NULL)
	{
		printf("%d->",p->data);
		p=p->next;
	}
	printf("NULL");
}
void merge(struct node *a,struct node *b) 
{

 
  head=NULL;
  temp=NULL;
  if (a == NULL) 
    head=b;
  else if (b==NULL) 
    head=a;
  while(a!=NULL && b!=NULL)
  {
  if(head==NULL)
  { 
	  temp=(struct node *)malloc(sizeof(struct node));
	 head=temp;
  }
  else
  {
	 temp->next=(struct node *)malloc(sizeof(struct node));
	 temp=temp->next;
  }
  if(a->data <= b->data)
  {
	  temp->data=a->data;
	  a=a->next;
  }
  else
  {
      temp->data=b->data;
	  b=b->next;
  }
  }
  while(a!=NULL)
  {
	
	 temp->next=(struct node *)malloc(sizeof(struct node));
	 temp=temp->next;
	 temp->data=a->data;
	 a=a->next;
  }
  while(b!=NULL)
  {
	
	 temp->next=(struct node *)malloc(sizeof(struct node));
	 temp=temp->next;
	 temp->data=b->data;
	 b=b->next;
  }
  temp->next=NULL;
  display(head);
}

	 
	 


    


 
  
  

// circular_linkedlist.c.cpp : Defines the entry point for the console application.
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
void circular(struct node *);
void display(struct node *);
void displayl(struct node *);
void main()
{
	struct node *head,*temp,*x;
	int n,num;
	head=NULL;
	printf("enter a number of elements");
	scanf("%d",&n);
	while(n>0)
	{
		printf("enter number ");
		scanf("%d",&num);
		temp=(struct node *)malloc(sizeof(struct node));
		temp->data=num;
		temp->next=NULL;
		if(head==NULL)
		{
		head=temp;
		x=head;
		}
		else
		{
			x->next=temp;
			x=temp;
		}
		n--;
	}
	
	display(head);
	
	printf("creating circular list\n");
	circular(head);
	displayl(head);
	getch();
	return ;
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
void circular(struct node *h)
{
	struct node *t;
	t=h;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next=h;
	
}
void displayl(struct node *t)
{
	struct node *temp,*head;
	printf("%d->",t->data);
	head=temp=t->next;
	do
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}while(temp!=head);
}

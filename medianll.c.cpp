// medianll.c.cpp : Defines the entry point for the console application.
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
void delete_n(int k);
int count(struct node *);
void main()
{
	struct node *head,*temp,*x;
	int n,num,i,p,b,s;
	head=NULL;
	printf("enter a number of elements");
	scanf("%d",&p);
	while(p>0)
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
		p--;
	}
	i=count(head);
	display(head);
	temp=head;
	if(i%2==0)
	{
	i=i/2;
	for(b=1;b<i;b++)
	{
		temp=temp->next;
	}
	s=temp->data;
	temp=temp->next;
	s=s+temp->data;
	printf("median is: %f",(float)s/2);
	}
	else
	{
		i=i/2;
		for(b=1;b<=i;b++)
	{
		temp=temp->next;
	}
	s=temp->data;
	printf("%d",temp->data);
	printf("median is: %f", (float)s);
	}
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
int count(struct node *p)
{
	int i;
	for(i=0;p!=NULL;p=p->next)
		i++;
	return i;
}




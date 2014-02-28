// n_element.c.cpp : Defines the entry point for the console application.
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
	int n,num,i,p,a,b;
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
	printf("enter the n value");
	scanf("%d",&n);
	//displaying nth value from the end
	temp=head;
	for(b=0;b<(i-n);b++)
	{
		temp=temp->next;
	}
	a=temp->data;
	printf("nth value is: %d",a);
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

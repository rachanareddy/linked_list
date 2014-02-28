// deletevalue.c.cpp : Defines the entry point for the console application.
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
void delete_n(struct node **);
void display(struct node *);
void delnode(struct node **,int x);
void main()
{
	struct node *head,*temp,*x;
	int n,num,k;
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
	delete_n(&head);
	display(head);
	printf("using recursion\n");
	scanf("%d",&k);
	delnode(&head,4);
	display(head);
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
void delete_n(struct node **h)
{
	struct node *temp,*prev;
	int k;
	printf("enter the element to be deleted\n");
	scanf("%d",&k);
	if((*h)->data==k)
	{
		temp=*h;
		*h=(*h)->next;
		free(temp);
		return;
	}
	temp=(*h)->next;
	prev=*h;
	while(temp!=NULL)
	{
		if(temp->data==k)
			break;
		else
		{
			prev=temp;
			temp=temp->next;
		}
	}
	if(temp==NULL)
		printf("element does not exist");
	else
	{
		prev->next=temp->next;
		free(temp);
	}
}
//using recursion
void delnode(struct node **h,int k)
{
	struct node *next;
	if(*h==NULL)
		printf("doesnot exist");
	if((*h)->data==k)
	{
		next=(*h)->next;
		free(*h);
		*h=next;
	}
	else
	delnode(&((*h)->next),k);
}

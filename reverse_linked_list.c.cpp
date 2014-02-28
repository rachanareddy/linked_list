// reverse_linked_list.c.cpp : Defines the entry point for the console application.
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

struct node *reverse_list(struct node *);
struct node *reverse_list1(struct node *);
void main()
{
	struct node *head,*temp,*h;
	int num,n,i,rem;
	head=NULL;
	printf("enter a number");
	scanf("%d",&num);
	while(num!=0)
	{
		rem=num%10;
		temp=(struct node *)malloc(sizeof(struct node));
		temp->data=rem;
		temp->next=head;
		head=temp;
		num=num/10;
	}
	display(head);	
	
	printf("reversing using iterative");
	head=reverse_list(head);
	display(head);
	printf("reversing using recursion (reversing already reversed list)");
	head=reverse_list1(head);
	display(head);
	getch();
	return ;
}
void append(struct node **h)
{
	if(*h==NULL)
	{
		*h=(struct node *)malloc(sizeof(struct node));
		printf("\n Enter data:");
		scanf("%d",(*h)->data);
		(*h)->next=NULL;
	}
	else
		append(&(*h)->next);
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
//iterative
struct node *reverse_list(struct node *h)
{
	struct node *prev,*cur,*pnext;
	if(h==NULL)
		return NULL;
	prev=NULL;
	cur=h;
	do
	{
		pnext=cur->next;
		cur->next=prev;
		prev=cur;
		cur=pnext;
	}while(cur!=NULL);
	return prev;
}
//recursive
struct node *reverse_list1(struct node *h)
{
	struct node *tmp;
	if(h==NULL)
		return NULL;
	if(h->next==NULL)
		return h;
	tmp=reverse_list1(h->next);
	(h->next)->next=h;
	h->next=NULL;
	return tmp;
}

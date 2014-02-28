// middle_doubly.c.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next,*prev;
};
void display(struct node *);
void middle(struct node *);
void main()
{
	struct node *head,*temp,*x,*prev;
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
		head->prev=NULL;
		x=head;
		}
		else
		{
			x->next=temp;
			temp->prev=x;
			x=temp;
		}
		n--;
	}
	
	display(head);
	middle(head);
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
void middle(struct node *head)
{
    struct node *slowptr = head;
    struct node *fastptr = head;
 
    if (head!=NULL)
    {
        while (fastptr != NULL && fastptr->next != NULL)
        {
            fastptr = fastptr->next->next;
            slowptr = slowptr->next;
        }
        printf("middle element is %d\n\n", slowptr->data);
    }
}

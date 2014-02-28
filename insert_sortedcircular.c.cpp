// insert_sortedcircular.c.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
 
struct node
{
  int data;
  struct node *next;
};
 

void sortedInsert(struct node** head, struct node* temp)
{
  struct node* current;
  current= *head;
  if (current == NULL)
  {
     temp->next = temp;
     *head = temp;
  }
 
 
  else if (current->data >= temp->data)
  {
    while(current->next != *head)
        current = current->next;
    current->next = temp;
    temp->next = *head;
    *head = temp;
  }
 
 
  else
  {
    
    while (current->next!= *head && (current->next)->data < temp->data)
      current = current->next;
 
    temp->next = current->next;
    current->next = temp;
  }
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
void main()
{
  struct node *temp,*head;
  int a[6];
  int listsize, i,num;
  head = NULL;
  for(i = 0; i< 4; i++)
  {
	printf("enter a number to insert");
    scanf("%d",&a[i]);
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = a[i];
    sortedInsert(&head,temp);
  }
 
  displayl(head);
  getch();
  return ;
}

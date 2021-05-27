#include <stdio.h>
#include <stdlib.h>

typedef struct nod
{
	int data;
	struct nod *next;
} node;

node *search(node *head,int input)
{
    node *curr=head;
    while(curr!=NULL && curr->data!= input)
    {
        curr=curr->next;
    }
    return curr;
}

node *insert(node *head,int input)
{
    node *tail=head;
    node *newnode=malloc(sizeof(node));
    newnode->data=strdup(input);
    newnode->next=NULL;

    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        while(tail->next!=NULL)
        {
            tail=tail->next;
        }
        tail->next=newnode;
    }
    return head;
}

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *head=NULL,*cpt=NULL,*newnode=NULL;
struct node *createlist()
{
	int i,data,n;
	printf("Enter the number of nodes: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter info[node %d]:- ",i+1);
	    scanf("%d",&data);
	    newnode->data=data;
		newnode->link=NULL;
		if(head==NULL)
		{
		   head=newnode;
		   cpt=newnode;
		}
		else
		{
		    cpt->link=newnode;
		    cpt=cpt->link;
		}
	}
	return head;
}
void display(struct node *head)
{
	struct node *cpt=head;
	printf("Linked list as follows: \n");
	printf("[head]->");
	while(cpt!=NULL)
	{
		printf("%d->",cpt->data);
		cpt=cpt->link;
	}
	printf("[NULL]\n");
}
struct node *rev(struct node *head)
{
	struct node *prev=NULL,*curr=head,*next=NULL;
	while(curr!=NULL)
	{
		next=curr->link;
	    curr->link=prev; 
		prev=curr;
		curr=next;
    }
	return prev;
}
int main()
{
	int n;
	struct node *head=NULL,*reve=NULL;
	head=createlist();
	display(head);
	reve=rev(head);
	display(reve);
	return 0;
}

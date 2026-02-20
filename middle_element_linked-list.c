#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *head=NULL,*cpt=NULL,*newnode=NULL;
struct node *createlist(int n)
{
	int i,data;
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
void middle_ele(struct node *head)
{
	struct node *slow=head,*fast=head;
	while(fast!=NULL && fast->link!=NULL)
	{
		slow=slow->link;
		fast=fast->link->link;
	}
	printf("Middle element of linked list is: %d",slow->data);
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
int main()
{
	int n;
	struct node *head=NULL;
	printf("Enter the number of nodes you want to enter: ");
	scanf("%d",&n);
	head=createlist(n);
	display(head);
	middle_ele(head);
	return 0;
}
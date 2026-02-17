// Performing various addition operations in linked list
#include<stdio.h>
#include<stdlib.h>
int n,total=10,avail=0;
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
		avail=avail+1;
	}
	return head;
}
void display()
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
void addbeg(int data)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	if(avail==total)
	{
		printf("List is full");
	}
	else
	{
		newnode->data=data;
	    newnode->link=head;
	    head=newnode;
	    avail=avail+1;
	    printf("\nUpdated Linked list is as follows:\n");
	    display(head);
    }
}
void addend(int data)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	if(avail==total)
	{
		printf("\n!!!List is full!!!");
	}
	else
	{
		newnode->data=data;
	    newnode->link=NULL;
	    if(head==NULL)
	    {
		    head=newnode;
		    return;
	    }  
	    struct node *cpt=head;
	    while(cpt->link!=NULL)
	    {
		    cpt=cpt->link;
	    }
	    cpt->link=newnode;
		avail=avail+1;
		printf("\n\nUpdated Linked list is as follows:\n");
		display(head);
    }
}
void search(int key,int data)
{
	int flag=0;
	int i=0;
	struct node *current=head;
	while(current!=NULL)
	{
		if(current->data==key)
		{
			flag=1;
			if(avail==total)
			{
				printf("\nList is full");
			}
			else
			{
				struct node *newnode=(struct node*)malloc(sizeof(struct node));
			    newnode->data=data;
			    newnode->link=current->link;
			    current->link=newnode;
			    avail=avail+1;
			    break;
			}
		}
		i++;
		current=current->link;
	}
	if(flag)
	{
		printf("\n\nElement is present in the list at index: %d",i);
	}
	else
	{
		printf("\n\nElement is not present in the list");
	}
	if(avail!=total){
	printf("\nUpdated Linked list is as follows:\n");
	display(head);}
}
int main()
{
	int info,choice;
	struct node *head=NULL;
	printf("Enter the number of nodes you want to enter: ");
	scanf("%d",&n);
	if(n>=10)
	{
		printf("List can have maximum 10 nodes!!!");
	}
	else
	{
		head=createlist(n);
	    printf("Linked list is as follows: \n");
	    display(head);
	
	printf("\n1.Addition at beginning \n2.Addition at end\n3.Addition after given node\n4.Display the list\n5.Exit");
	do
	{
		printf("\nEnter your choice: ");
	    scanf("%d",&choice);
		if(choice<=3)
	    {
		     printf("\nEnter data to be entered: ");
	         scanf("%d",&info);
	    } 
	    switch(choice)
	    {
		    case 1:
			    addbeg(info);
			    break;
		    case 2:
			    addend(info);
			    break;
		    case 3:
			    printf("\nEnter the node after you want to add: ");
			    scanf("%d",&n);
			    search(n,info);
			    break;
			case 4:
				display(head);
				break;
		    case 5:
		    	printf("EXIT POINT!!!");
			    break;
		    default:
			    printf("\n\n!!!INVALID CHOICE!!!");
			    break;
	    }
    }
	while(choice!=5);
	}
	return 0;
}

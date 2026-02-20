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
	int n,i,data;
	printf("Enter the number of nodes: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter node %d: ",i+1);
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
	if(head==NULL)
	{
		printf("List is empty!!!");
	}
	else
	{
		printf("[HEAD->]");
		while(cpt!=NULL)
		{
			printf("%d->",cpt->data);
			cpt=cpt->link;
		}
		printf("[NULL]");
	}
}
struct node *delete_node(struct node *head) {
    int ele;
    printf("\nEnter the element you want to delete: ");
    scanf("%d", &ele);
    struct node *temp = head, *prev = NULL;
    while (temp != NULL) {
        if (temp->data == ele) {
            if (prev == NULL) {  // deleting first node
                head = temp->link;
            } else {
                prev->link = temp->link;
            }
            free(temp);
            printf("Node %d deleted successfully!\n", ele);
            return head;
        }
        prev = temp;
        temp = temp->link;
    }

    printf("Element %d not found in list!\n", ele);
    return head;
}
int main()
{
	struct node *head;
	head=createlist();
	display(head);
	head=delete_node(head);
	display(head);
	return 0;
}
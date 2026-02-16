//This is a menu driven program in C for performing various operations[basic] on array.
//This program helps in clear understanding of while loop, switch statement and opeartions like add, delete,display ,search performed on array

#include<stdio.h>
int arr[10],n;
void insert()
{
	int data,pos,i;
	if(n>=10)
	{
		printf("ARRAY IS FULL!!");
	}
	else
	{
		printf("Enter the data to be inserted: ");
		scanf("%d",&data);
		printf("Enter the position at which you want: ");
		scanf("%d",&pos);
		for(i=n-1;i>=pos;i--)
		{
			arr[i+1]=arr[i];
		}
		arr[pos-1]=data;
		n=n+1;
		printf("ELEMENT INSERTED SUCCESSFULLY!!");
	}
}
void delete_by_value()
{
	int i,data,x,found=0;
	printf("Enter the element to be deleted: ");
	scanf("%d",&data);
	for(i=0;i<n;i++)
	{
		if(arr[i]==data)
		{
			x=i;
			found=found+1;
		}
	}
	if(found==0)
	{
		printf("ELEMENT IS NOT PRESENT IN ARRAY!!!");
	}
	else
	{
		for(i=x;i<n;i++)
		{
			arr[i]=arr[i+1];
		}
		n--;
		printf("Element deleted successfully");
	}
}
void delete_by_pos()
{
	int i,pos,j,found=0;
	printf("Enter the position which you want to delete: ");
	scanf("%d",&pos);
	if(pos<1 || pos>n+1)
	{
		printf("POSITION DOES NOT EXIST!!!");
	}
	else
	{
		for(i=pos-1;i<n;i++)
		{
			arr[i]=arr[i+1];
		}
		n--;
		printf("Element deleted successfully!!!");
	}
}
void display()
{
	int i;
	printf("Your array is as follows: \n");
	for(i=0;i<n;i++)
	{
		printf("%d",arr[i]);
		printf("\n");
	}
}
void search()
{
	int ele,i,found=0;
	printf("Enter the element to be serached: ");
	scanf("%d",&ele);
	for(i=0;i<n;i++)
	{
		if(arr[i]==ele)
		{
			printf("Element found at position: %d",i+1);
			found++;
		}
	}
	if(found==0)
	{
		printf("Element not found!!!");
	}
}
void update()
{
	int pos,ele;
	printf("Enter the position which you want to update: ");
	scanf("%d",&pos);
	if(pos<0 || pos>n)
	{
		printf("Position does not exist!!!");
	}
	else
	{
		printf("Enter the data to be updated: ");
	    scanf("%d",&ele);
		arr[pos-1]=ele;
		printf("Array updated successfully");
	}
}
int main()
{
	int i,choice;
	printf("Enter the number of elements you want to enter:- ");
	scanf("%d",&n);
	printf("Enter the elements in your array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	display();
	printf("-----------MENU-------------");
	printf("\n1.INSERT\n2.DELETE BY VALUE\n3.DELETE BY POSITION\n4.DISPLAY\n5.SEARCH\n6.UPDATE\n7.EXIT");
	do
	{
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert();
				break;
			case 2:
				delete_by_value();
				break;
			case 3:
				delete_by_pos();
				break;
			case 4:
				display();
				break;
			case 5:
				search();
				break;
			case 6:
				update();
				break;
			case 7:
				printf("EXIT POINT!!!");
				break;
			default:
				printf("INVALID CHOICE!!!");
				break;
		}
	}
	while(choice!=7);
	return 0;
}

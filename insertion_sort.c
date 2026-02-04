#include<stdio.h>
void print_array(int n,int arr[])
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
}
void insertion_sort(int n,int arr[])
{
	int i,curr,prev;
	for(i=1;i<n;i++)
	{
		curr=arr[i];
		prev=i-1;
		while(prev>=0 && arr[prev]>curr)
		{
			arr[prev+1]=arr[prev];
			prev=prev-1;
		}
		arr[prev+1]=curr;
	}
	printf("\nSorted array is as follows:\n");
	print_array(n,arr);
}
int main()
{
	int n,i;
	printf("Enter the number of elements in array: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter elements in your array: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Entered array is as follows: \n");
	print_array(n,arr);
	insertion_sort(n,arr);
	return 0;
}

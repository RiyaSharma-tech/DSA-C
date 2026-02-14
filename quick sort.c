#include<stdio.h>
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int arr[],int low,int high)
{
	int i=(low-1),j,pivot=arr[high];
	for(j=low;j<high;j++)
	{
		if(arr[j]<=pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return i+1;
}
void quick_sort(int arr[],int low,int high)
{
	if(low<high)
	{
		int p=partition(arr,low,high);
		quick_sort(arr,low,p-1);
		quick_sort(arr,p+1,high);
	}
}
void print_arr(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
}
int main()
{
	int arr[20],n,i;
	printf("Enter the number of elements you want in your array: ");
	scanf("%d",&n);
	printf("Enter the elements in your array:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Original array is as follows: \n");
	print_arr(arr,n);
	quick_sort(arr,0,n-1);
	printf("\nSorted array is as follows: \n");
	print_arr(arr,n);
	return 0;
}

#include<stdio.h>
int search(int arr[],int lb,int ub,int ele)
{
	if(lb>ub)
	{
		return -1;
	}
    int mid=(lb+ub)/2;
	if(arr[mid]==ele)
	{
		return mid;
	}
	else if(ele<arr[mid])
	{
		return search(arr,lb,mid-1,ele);
	}
	else
	{
		return search(arr,mid+1,ub,ele);
	}
}
int main()
{
	int arr[20],i,j,n,ele,find;
	int lb=0;
	printf("Enter the number of elements in your array: ");
	scanf("%d",&n);
	printf("Enter elements in your array: \n");
	int ub=n-1;
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Entered array is as follows: \n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",arr[i]);
	}
	printf("Enter the element to be searched: ");
	scanf("%d",&ele);
	find=search(arr,lb,ub,ele);
	if(find>-1)
	{
		printf("Element found at index: %d",find);
		printf("\nElement found at position: %d",find+1);
	}
	else
	{
		printf("Element not found!!");	
	}
	return 0;
}

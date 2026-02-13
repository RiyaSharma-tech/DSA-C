#include<stdio.h>
#include<stdlib.h>
void merge(int arr[],int left,int mid,int right)
{
	int i,j,k;
	int n1=mid-left+1;
	int n2=right-mid;
	int *leftarr=(int *)malloc(n1 *sizeof(int));
	int *rightarr=(int *)malloc(n2 *sizeof(int));
	for(i=0;i<n1;i++)
	{
		leftarr[i]=arr[left+i];
	}
	for(j=0;j<n2;j++)
	{
		rightarr[j]=arr[mid+1+j];
	}
	i=j=0,k=left;
	while(i<n1 && j<n2)
	{
		if(leftarr[i]<=rightarr[j])
		{
			arr[k]=leftarr[i];
			i++;
		}
		else
		{
			arr[k]=rightarr[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		arr[k]=leftarr[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k]=rightarr[j];
		j++;
		k++;
	}
	free(leftarr);
	free(rightarr);
}
void merge_sort(int arr[],int left,int right)
{
	if(left<right)
	{
		int mid;
		mid=(left+right)/2;
		merge_sort(arr,left,mid);
		merge_sort(arr,mid+1,right);
		merge(arr,left,mid,right);
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
	merge_sort(arr,0,n-1);
	printf("\nSorted array is as follows: \n");
	print_arr(arr,n);
	return 0;
}

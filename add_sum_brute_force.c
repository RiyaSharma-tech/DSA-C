//Time complexity-O(n^2)
//Space complexity-O(1)
//Two sum problem using nested loop.

#include<stdio.h>
int main()
{
	int n;
	printf("Enter the number of elements you want in your array: ");
	scanf("%d",&n);
	int arr[n],i,j,sum=0,count=0,target;
	printf("Enter elements in array:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Original array: \n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\nEnter the target sum: ");
	scanf("%d",&target);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			sum=arr[i]+arr[j];
			if(sum==target)
			{
				printf("\nTarget achieved at indexes: %d and %d",i,j);
				count++;
				break;
			}
		}
	}
	printf("\nTotal pairs that meet target are: %d",count);
	if(count==0)
	{
		printf("No two elements make sum equal to target");
    }
	return 0;
}

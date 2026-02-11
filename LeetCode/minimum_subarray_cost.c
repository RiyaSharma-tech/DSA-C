#include<stdio.h>
#include<limits.h>
int main()
{
 	int n;
 	printf("Enter the elements in your array: ");
 	scanf("%d",&n);
 	if(n<3)
 	{
	 	printf("Atleast 3 elements should be there");	
	}
	else
	{
		int arr[n],i,min_1,min_2,cost,f_cost;
 		printf("Enter the elements in array: ");
 		for(i=0;i<n;i++)
 		{
	 		scanf("%d",&arr[i]);	
		}
		f_cost=arr[0];
		min_1=INT_MAX;
		min_2=INT_MAX;
		for(i=1;i<n;i++)
		{
			if(arr[i]<min_1)
			{	
				min_2=min_1;
				min_1=arr[i];
			}
			else if(arr[i]<min_2)
			{
				min_2=arr[i];
			}
		}
		cost=f_cost+min_1+min_2;
		printf("Minimum cost is: %d",cost);
	}
	return 0;
}

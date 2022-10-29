#include<stdio.h>
int binarysearch(int a[],int low,int high,int x)
{
	int mid;
	if(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==x)
		{
			return 1;
		}
		else if(a[mid]<x)
		{
			return binarysearch(a,mid+1,high,x);
		}
		else
		{
			return binarysearch(a,low,mid-1,x);
		}
	}
	return 0;
}

int main()
{
	int a[100],n,i,x,z;
	printf("\nEnter bumber of elements=");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter element=");
		scanf("%d",&a[i]);
	}
	printf("\nEnter element to be searched=");
	scanf("%d",&x);
	z=binarysearch(a,0,n-1,x);
	if(z==1)
	{
		printf("\nElement is present...");
	}
	else
	{
		printf("\nElement is not present...");
	}
	return 0;
}

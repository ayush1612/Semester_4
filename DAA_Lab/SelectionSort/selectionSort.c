#include<stdlib.h>
#include<time.h>
void main()
{
	int n;
	clock_t start,end;
	double total;
	printf("Enter the number of elements in the array\n");
	scanf("%d",&n);
	
	printf("Enter %d elements in the array\n",n);
	int arr[n],i,j,ind=0;
	
	
	for(i=0;i<n;i++)
		arr[i]=rand();	
	
	start=clock();
	for(i=0;i<n;i++)
	{	
		ind=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[ind]>arr[j])
				ind=j;
		}
		//swapping the index
		int temp=arr[ind];
		arr[ind]=arr[i];
		arr[i]=temp;
	}
	end=clock();
	
	total=(double)(end-start)/CLOCKS_PER_SEC;
	printf("time taken=%f\n\n",total);
}

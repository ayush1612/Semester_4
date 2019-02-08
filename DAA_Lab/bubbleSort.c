#include<stdio.h>
#include<time.h>
void main()
{
	clock_t start,end;
	double total;
	int n,i,j;
  
	printf("Enter the number of elements");
	scanf("%d",&n);
	int arr[n];
  
	for(i=0;i<n;i++)
		arr[i]=rand();	
    
	//sorting the elements using bubble sort
	start=clock();
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	end=clock();
  
	total=(double)(end-start)/CLOCKS_PER_SEC;
	printf("%f",total);
}

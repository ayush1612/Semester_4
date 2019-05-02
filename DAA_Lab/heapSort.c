#include<time.h>
#include<stdio.h>
#include<stdlib.h>
int h[50];

void heapify(int h[],int n)
{
	int i,j,l,k,heap,v;
	for(i=n/2;i>=1;i--)
	{
		k=i,v=h[k],heap=0;
		while(!heap&&2*k<=n)
		{
			j=2*k;
			if(j<n)
				if(h[j]<h[j+1])
					j++;
				if(v>=h[j])
					heap=1;
				else
				{
					h[k]=h[j];
					k=j;
				}
		}
		h[k]=v;
	}
}
void main()
{
	int i,n,size,t;
	clock_t start,end;
	double tottime;
	printf("Enter n\n");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
		scanf("%d",&h[i]);
	start=clock();
	heapify(h,n);
	printf("Elements heapified:");
	for(i=1;i<=n;i++)
		printf("%d\n",h[i]);
		
	for(i=n;i>=1;i--)
	{
		t=h[1];
		h[1]=h[i];
		h[i]=t;
		size=i-1;
		heapify(h,size);
	}
	end=clock();
	printf("Elements Sorted:\n");
	
	for(i=1;i<=n;i++)
		printf("%d\n",h[i]);
	tottime=(double)(end-start)/(CLOCKS_PER_SEC);
	printf("Time taken is %d\n",tottime);
}

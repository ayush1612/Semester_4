#include<stdio.h>
#define SIZE 7

int n;

//the process part
void warshall(int R[SIZE][SIZE])
{
	int i,j,k;
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				R[i][j]=R[i][j] || (R[i][k] && R[k][j]);
	
	//displaying the array
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",R[i][j]);
		printf("\n");
	}
}


//the main operation
void main()
{
	//input
	int R[SIZE][SIZE];		//initialized the array with the size
	printf("Enter the number of elements in the array\n");
	scanf("%d",&n);			//number of elements in the array
	
	printf("Enter %d elements in the array\n",(n*n));
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&R[i][j]);
	
	//process
	warshall(R);
}


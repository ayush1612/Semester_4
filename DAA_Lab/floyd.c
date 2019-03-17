#include<stdio.h>
#define SIZE 7

int n;
//min fucntion definition
int min(int a,int b)
{
if(a>b)
	return a;
else 
	return b;
}


//floyd's algorithm
void Floyd(int D[SIZE][SIZE])
{
	int i,j,k;
	
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
	
	//displaying the matrix
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",D[i][j]);
		printf("\n");
	}
}
		
//the main operation

void main()
{
	int D[SIZE][SIZE];	//the main array
	
	//input 
	printf("Enter the number of rows and columns you want in the array\n");
	scanf("%d",&n);
	
	printf("Enter %d elements in the array\n",(n*n));
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&D[i][j]);
	
	//process
	Floyd(D);
}

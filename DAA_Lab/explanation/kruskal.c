#include<stdio.h>
void main()
{
	int a,b;					// to keep the minimum edges' indices
	int mincost=0,min=0;		// to keep the track of the mincost after adding every new edge
	int i,j;					// to traverse the matrix
	int parent[10];				// to store the parent nodes
	int mat[10][10];			// to input the adjacency matrix
	int source;
	int ne=1,n;
	
	//input the number of nodes 
	printf("Enter the number of nodes\n");
	scanf("%d",&n);
	
	//input the adjacency matrix to find the connections in the original graph
	printf("Enter the adjacency matrix\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&mat[i][j]);
			
	//make all the parent nodes as 0
	for(i=0;i<n;i++)
		parent[i]=0;
		
	printf("Enter the source node\n");
	scanf("%d",&source);
	
	//make the graph with the smallest spanniong cost
	while(ne<n)
	{	
		min=999;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{	
				//find the smallest edge in each iteration and then if their parents are not the same create an edge between them
				if(min>mat[i][j])
				{
					a=i;
					b=j;
					min=mat[i][j];
				}
			}
		}
		
		// to check the parent of 'a' 
		while(parent[a])
			a=parent[a];
		
		//to check the parent of 'b'
		while(parent[b])
			b=parent[b];
			
		//if their parents are same then probably it will create a loop which will not give the correct minimum spanning cost
		if(a!=b)
		{
			printf("Edge %d -> %d\t weight:%d\n",a,b,min);
			mincost=mincost+min;	//calculating the minimum cost
			ne++;					// incrementing the value to calculate the new edge
			parent[b]=a;		//as 'a' is connected to 'b'
		}
	//make the values of the matrix as 999
		mat[a][b]=mat[b][a]=999;
	}
	printf("Minimum cost=%d\n",mincost);
}

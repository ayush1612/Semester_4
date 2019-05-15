#include<stdio.h>
void main()
{	
	int min,mincost=0,ne=1,n;	//to keep the track of the minimum cost 
	int i,j;					//traversing variables
	int mat[10][10];	//to input the adjacency matrix
	int visited[10];	// to keep the record of the visited nodes
	int source;			// to input the source node
	int a,b;	//to store the index of the minimum values
	//enter the number of nodes
	printf("Enter the number of nodes\n");
	scanf("%d",&n);
	
	//take the adjacency matrix as input
	printf("Enter the adjacency matrix\n");
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&mat[i][j]);
	
	//make all the elements  not visited
	
	for(i=0;i<n;i++)
		visited[i]=0;
	
	//make the source node visited
	printf("Enter the source node\n");
	scanf("%d",&source);
	visited[source]=1;
	
	//make the edges
	while(ne<n)
	{
		min=999;
		//traverse through all the elements 
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				//find the smallest and replace it with the min value
				if(min>mat[i][j])
				{
					//check if the node is visited or not
					if(visited[i]==0)
						continue;
					else
					{
          //found the minimum weighted edge
          //found the indices of the minimum weighted edges
						min=mat[i][j];
						a=i;
						b=j;
					}
				}
			}
		}
							
		//if the node is finding the distance from itself the thing is it will be the smallest element(0)
		//if the nodes will be already having the edge between them 
		//In both the above cases make the distance between the elements as 999
		if(visited[a]==0||visited[b]==0)
		{
			printf("Edge %d -> %d\t weight=%d\n",a,b,min);
			mincost=mincost+min;
			visited[b]=1;
			ne++;
		}
		//Otherwise just make the edge between the nodes and then increment the value of ne thus showing that one edge is already created
		mat[a][b]=mat[b][a]=999;
	
	} //finally got all the edges and calculated the minimum cost
  printf("Minimum Cost=%d",mincost);
}

//Sample Input for testing :
/*
a-----b
| \   |
|   \ |
d-----c

0 4 1 3
4 0 2 999
1 2 0 5
3 999 5 0
*/
/*
Output:
Edge 0 -> 2	 weight=1
Edge 2 -> 1	 weight=2
Edge 0 -> 3	 weight=3
Minimum Cost=6
*/

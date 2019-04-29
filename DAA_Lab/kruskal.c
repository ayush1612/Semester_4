#include<stdio.h>
int ne=1,min_cost=0;
void main()
{
	int n,i,j,min,cost[20][20];
	int a,b,source,parent[20],u,v;
	printf("Enter the number of nodes\n");
	scanf("%d",&n);
	printf("Enter the cost matrix:\n");
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
		}
	}
	
	for(i=1;i<=n;i++)
		parent[i]=0;
	
	printf("Minimum Spanning Tree\n");
	while(ne<n)
	{
		min=999;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(cost[i][j]<min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		
		while(parent[u])
			u=parent[u];
		
		while(parent[v])
			v=parent[v];
		
		if(u!=v)
		{
			printf("edge %d \t (%d -> %d)=%d\n",ne++,a,b,min);
			min_cost=min_cost+min;
			parent[v]=u;
		}
		
		cost[a][b]=cost[b][a]=999;
	}
	printf("\n min cost = %d \n",min_cost);
}

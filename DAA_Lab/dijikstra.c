#include<stdio.h>

int dis[10];
int src;
int cost[10][10];
int n;

void dij()
{
	int i;
	int minind;
	for(i=1;i<=n;i++)
		dis[i]=cost[src][i];
	
	int flag[10];
	
	for(i=1;i<=n;i++)
		flag[i]=0;
	int count = 2;
	
	while(count<=n)
	{
		int min=999;
		//finding the shortest paths
		for(i=1;i<=n;i++)
			if(!flag[i] && dis[i]<min)
			{
				min=dis[i];
				minind=i;
			}
		
		flag[minind]=1;
		count++;
		
		for(i=1;i<=n;i++)
			if(dis[i]>dis[minind]+cost[minind][i] && !flag[i])
				dis[i]=dis[minind]+cost[minind][i];
	}
}
	

void main()
{
	int i,j;

	
	printf("Enter the number of nodes you want to have\n");
	scanf("%d",&n);
	

	printf("Enter the cost matrix\n");
	
	for(i=1;i<n+1;i++)
		for(j=1;j<n+1;j++)
		{
			scanf("%d",&cost[i][j]);
			
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
					
	
	printf("Enter the source node\n");
	scanf("%d",&src);
	
	dij();
	
	printf("The shortest distances are:\n");
	for(i=1;i<n+1;i++)
		if(i!=src)
			printf("%d -> %d = %d\n",src,i,dis[i]);
}

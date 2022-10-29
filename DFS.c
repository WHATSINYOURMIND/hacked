#include<stdio.h>
int adj[10][10]={0},visited[10]={0},n;

void dfs(int node)
{
	int i;
	visited[node]=1;
	printf("%d ",node);
	for(i=0;i<n;i++)
	{
		if(adj[node][i]==1 && visited[i]==0)
		{
			dfs(i);
		}
	}
}

int main()
{
	int e,i,v1,v2,node;
	printf("\nEnter number of vertices=");
	scanf("%d",&n);
	printf("\nEnter number of edges=");
	scanf("%d",&e);
	for(i=0;i<e;i++)
	{
		printf("\nEnter edge=");
		scanf("%d%d",&v1,&v2);
		adj[v1][v2]=adj[v2][v1]=1;
	}
	printf("\nEnter starting node=");
	scanf("%d",&node);
	dfs(node);
	return 0;
}

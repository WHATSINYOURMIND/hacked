#include<stdio.h>
int adj[10][10]={0},visited[10]={0},n;

void bfs(int node)
{
	int q[20],f=-1,r=-1,i,nd;
	
	visited[node]=1;
	q[++r]=node;
	while(f!=r)
	{
		nd=q[++f];
		printf("\t%d",nd);
		for(i=0;i<n;i++)
		{
			if(adj[nd][i]==1 && visited[i]==0)
			{
				visited[i]=1;
				q[++r]=i;
			}
		}
	}
}
int main()
{
	int e,i,v1,v2,node;
	printf("\nEnter nos of nodes=");
	scanf("%d",&n);
	printf("\nEnter nos of edges=");
	scanf("%d",&e);
	printf("\nEnter edge details\n");
	for(i=0;i<e;i++)
	{
		printf("\nEnter edge=");
		scanf("%d%d",&v1,&v2);
		adj[v1][v2]=adj[v2][v1]=1;
	}
	printf("\nEnter starting vertex=");
	scanf("%d",&node);
	bfs(node);
	return 0;
}

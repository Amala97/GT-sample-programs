#include<stdio.h>
#include<stdlib.h>
#define INFINITY 99999
void dijkstra(int G[10][10],int n, int startnode,int endnode);
void main()
{
int Graph[10][10],i,j,n,u,e;
printf("Enter the no of vertices: ");
scanf("%d",&n);
printf("Enter the adjacency matrix: \n");
for(i=0;i<n;i++)
        for(j=0;j<n;j++)
                scanf("%d",&Graph[i][j]);
printf("Enter the starting node: ");
scanf("%d",&u);
printf("Enter the ending node: ");
scanf("%d",&e);
dijkstra(Graph,n,u,e); 
}

void dijkstra(int G[10][10],int n, int startnode,int endnode)
{
int cost[10][10],distance[10],pred[10];
int visited[10],count,mindistance,nextnode,i,j;
for(i=0;i<n;i++)
	for(j=0;j<n;j++)
		if(G[i][j]==0)
			cost[i][j]=INFINITY;
		else
			cost[i][j]=G[i][j];
for(i=0;i<n;i++)
{
	distance[i]=cost[startnode][i];
	pred[i]=startnode;
	visited[i]=0;
}
distance[startnode]=0;
visited[startnode]=1;
count=1;

while(count<n-1)
{
mindistance=INFINITY;
for(i=0;i<n;i++)
	if(distance[i]<mindistance && !visited[i])
	{
		mindistance=distance[i];
		nextnode=i;
	}
visited[nextnode]=1;
for(i=0;i<n;i++)
	if(!visited[i])
		if(mindistance+cost[nextnode][i]<distance[i])
		{
			distance[i]=mindistance+cost[nextnode][i];
			pred[i]=nextnode;
		}
	count++;
}
printf("Shortest distance: %d\n",distance[endnode]);
j=endnode;
printf("Path: \n %d",endnode);
do
{
	j=pred[j];
	printf("<-%d",j);
}while(j!=startnode);
}


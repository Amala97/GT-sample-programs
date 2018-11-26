#include<stdio.h>
int adjacent[20][20],visited[20];
int v,count;
void printcomponent(int node);
void main()
{
int e,v1,v2,i,j,noc;
count=0;
printf("Enter the no of vertices in the graph:  ");
scanf("%d",&v);
for(i=0;i<20;i++)
	visited[i]=0;
printf("Enter the no of edges in the graph:  ");
scanf("%d",&e);
for(i=0;i<v;i++)
        for(j=0;j<v;j++)
                adjacent[i][j]=0;
for(i=0;i<e;i++)
        {
        printf("Enter the terminal vertices of edge %d: ",i);
        scanf("%d %d",&v1,&v2);
        adjacent[v1][v2]=1;
        adjacent[v2][v1]=1;
        }
noc=1;
while(count<v)
{
for(j=0;j<v;j++)
	if(!visited[j])
	{
		printf("Component %d:\n",noc);
		printcomponent(j);
		printf("\n");
		noc++;
	}
}
}
void printcomponent(int node)
{
	count++;
	int k;
	visited[node]=1;
	printf("%d  ",node);
	for(k=0;k<v;k++)
	{
		if(adjacent[node][k]==1 && !visited[k])
			printcomponent(k);
	}
}





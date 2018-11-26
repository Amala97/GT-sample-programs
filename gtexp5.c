#include<stdio.h>
#define INFINITY 99999
void updatekey(int node);
int v,adjacent[20][20],precd[20],key[20],mstset[20];
void main()
{
int i,j,small,count;
count=0;
for(i=0;i<20;i++)
	{
	mstset[i]=0;
	key[i]=INFINITY;
	}
key[0]=0;
printf("Enter the no of vertices in the graph:  ");
scanf("%d",&v);
printf("Enter the adjacency matrix:\n");
for(i=0;i<v;i++)
	for(j=0;j<v;j++)
		{
		scanf("%d",&adjacent[i][j]);
		if(adjacent[i][j]==0)
			adjacent[i][j]=INFINITY;
		}
small=0;
precd[small]=small;
while(count<v)
{

	for(i=0;i<v;i++)
	{
		if(!mstset[i])
		{
		small=i;
		break;
		}
	}
        for(;i<v;i++)
        {
                if(!mstset[i] && key[i]<key[small])
                small=i;
        }

mstset[small]=1;
count++;
updatekey(small);
}
for(i=1;i<v;i++)
printf("%d <- %d : %d\n",i,precd[i],key[i]);
}

void updatekey(int node)
{
	int k;
	for(k=0;k<v;k++)
		if(!mstset[k] && adjacent[node][k]<key[k])
			{
			key[k]=adjacent[node][k];
			precd[k]=node;
			}
}

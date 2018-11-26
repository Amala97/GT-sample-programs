#include<stdio.h>
#include<stdlib.h>
void main()
{
int v,e,v1,v2,i,j;
int incident[20][20],adjacent[20][20];
char edge;
printf("Enter the no of vertices in the graph:  ");
scanf("%d",&v);
printf("Enter the no of edges in the graph:  ");
scanf("%d",&e);
for(i=0;i<v;i++)
	for(j=0;j<e;j++)
		incident[i][j]=0;
for(i=0;i<v;i++)
        for(j=0;j<v;j++)
                adjacent[i][j]=0;

edge='a';
for(i=0;i<e;i++)
	{
	printf("Enter the terminal vertices of edge %c : ",edge++);
	scanf("%d %d",&v1,&v2);
	incident[v1][i]=1;
	incident[v2][i]=1;
	adjacent[v1][v2]=1;
	adjacent[v2][v1]=1;
	}
printf("Incident matrix representation:\n");
for(i=0;i<v;i++)
	{
  	for(j=0;j<e;j++) 
    		{
    		printf("%d  ",incident[i][j]);
    		}
  	printf("\n");
  	}
printf("\nAdjacency matrix representation:\n");
for(i=0;i<v;i++)
        {
        for(j=0;j<v;j++) 
                {
                printf("%d  ",adjacent[i][j]);
                }
        printf("\n");
        }

}

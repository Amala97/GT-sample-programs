
#include<stdio.h>
#include<stdlib.h>
struct node
{
int val;
struct node *next;
};
typedef struct node NODE;
struct list
{ 
NODE *head;
};
typedef struct list LIST; 

struct grap
{
int v;
LIST *array;
};
typedef struct grap GRAPH;
NODE* NewNode(int dest)
{
NODE *newnode = (NODE *)malloc(sizeof(NODE));
newnode->val = dest;
newnode->next=NULL;
}

GRAPH* CreateGraph(int v)
{
GRAPH *graph = (GRAPH *)malloc(sizeof(GRAPH));
graph->v=v;
graph->array = (LIST *)malloc(v * sizeof(LIST));
int i;
for(i=0;i<v;i++)
	graph->array[i].head=NULL;
return graph;
}
void AddEdge(GRAPH *graph,int src, int dest)
{
NODE *newNode = NewNode(dest);
newNode->next =graph->array[src].head;
graph->array[src].head = newNode;
newNode = NewNode(src);
newNode->next=graph->array[dest].head;
graph->array[dest].head=newNode;
}
void printgraph(GRAPH *graph)
{
int j;
for(j=0;j< graph->v; ++j)
{
NODE * pCrawl= graph->array[j].head;
printf("Adjacency list of vertex %d\n",j);
while(pCrawl)
{
printf(" -> %d",pCrawl->val);
pCrawl=pCrawl->next;
}
printf("\n");
}
}
void main()
{
int v,e,v1,v2,i,j;
int incident[20][20],adjacent[20][20];
char edge;
printf("Enter the no of vertices in the graph:  ");
scanf("%d",&v);
GRAPH *graph = CreateGraph(v);
printf("Enter the no of edges in the graph:  ");
scanf("%d",&e);
edge='a';
for(i=0;i<e;i++)
        {
        printf("Enter the terminal vertices of edge %c : ",edge++);
        scanf("%d %d",&v1,&v2);
	AddEdge(graph,v1,v2);
	}
printgraph(graph);
}

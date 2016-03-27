#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
using namespace std;

struct adjlistnode{
	int dest;
	struct adjlistnode* next;
};
struct adjlist {
	adjlistnode *head;
};
struct graph{

	int V;
	struct adjlist *array;

};

struct adjlistnode* newadjlistnode(int dest)
{
	struct adjlistnode* newnode = (struct adjlistnode*) malloc(sizeof(struct adjlistnode));
	newnode->dest = dest;
	newnode->next = NULL;
	return newnode;
}

struct graph* createGraph(int V)
{int i;
	struct graph* Graph = ( struct graph*) malloc(sizeof(struct graph));
	Graph->V = V;
	Graph->array = (struct adjlist*) malloc(V*sizeof(struct adjlist));

	for(i=0;i<V;i++)
	{
		Graph->array[i].head = NULL;
	}
	return Graph;
}

void addEdge(struct graph* Graph, int src, int dest)
{
	struct adjlistnode* newnode = newadjlistnode(dest);
	newnode->next = Graph->array[src].head;
	Graph->array[dest].head = newnode; 
	newnode = newadjlistnode(src);
	newnode->next= Graph->array[dest].head;
	Graph->array[dest].head = newnode;
}

void printGraph(struct graph* Graph)
{
    int v;
    for (v = 0; v < Graph->V; ++v)
    {
        struct adjlistnode* pCrawl = Graph->array[v].head;
        std::cout<<endl;
        std::cout<<" Adjacency list of vertex"<< v <<endl;
        std::cout<<" head ";
        while (pCrawl)
        {
           std::cout<< " -> " << pCrawl->dest ;
            pCrawl = pCrawl->next;
        }
        std::cout<<endl;
    }
}
 
// Driver program to test above functions
int main()
{
    // create the graph given in above fugure
    int V = 5;
    struct graph* Graph = createGraph(V);
    addEdge(Graph, 0, 1);
    addEdge(Graph, 0, 4);
    addEdge(Graph, 1, 2);
    addEdge(Graph, 1, 3);
    addEdge(Graph, 1, 4);
    addEdge(Graph, 2, 3);
    addEdge(Graph, 3, 4);
 
    // print the adjacency list representation of the above graph
    printGraph(Graph);
 
    return 0;
}



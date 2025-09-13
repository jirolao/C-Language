#include <stdio.h>
#include <stdlib.h>

#define INF 256
#define GSIZE 5

//Adjacency List
typedef struct node {
    int vertex;
    int weight;
    struct node *link;
} List;

typedef struct {
    int num_vertices;
    List *LISTS[GSIZE];
} AdjList;

//Adjacency Matrix
typedef int AdjMat[GSIZE][GSIZE];

//linked List to store edges according to weights in Order ascending
typedef struct vert {
    int src, des;
    int weight;
    struct vert *link;
} *LL;

List* createNode(int vertex, int weight);
void insertEdge(AdjList *list, int source, int destination, int weight);
void displayUndirectedMatrix(AdjMat A);
void displayUndirectedList(AdjList A);
// Removed duplicate declaration
void displayDirectedList(AdjList A);
void insertList(LL *A, AdjList listDirected);

int main() {

    LL linklist = NULL;
    int i;

    AdjList listUndirected;
    listUndirected.num_vertices = 5;
    for (i = 0; i < GSIZE; i++) {
        listUndirected.LISTS[i] = NULL;
    }

    insertEdge(&listUndirected, 0, 1, 10);
    insertEdge(&listUndirected, 0, 2, 20);
    insertEdge(&listUndirected, 1, 0, 10);
    insertEdge(&listUndirected, 1, 3, 30);
    insertEdge(&listUndirected, 2, 0, 20);
    insertEdge(&listUndirected, 2, 3, 40);
    insertEdge(&listUndirected, 3, 1, 30);
    insertEdge(&listUndirected, 3, 4, 40);
    insertEdge(&listUndirected, 4, 3, 15);
    insertEdge(&listUndirected, 4, 1, 20);

    AdjMat matrixUndirected =
    {
        {INF, 10, 20, INF, INF},
        {10, INF, INF, 30, INF},
        {20, INF, INF, 40, INF},
        {INF, 30, 40, INF, 40},
        {INF, 20, INF, 15, INF}
    };

    AdjList listDirected = {5, {NULL}};
    insertEdge(&listDirected, 0, 1, 10);
    insertEdge(&listDirected, 1, 2, 5);
    insertEdge(&listDirected, 1, 3, 20);
    insertEdge(&listDirected, 2, 3, 30);
    insertEdge(&listDirected, 2, 4, 20);
    insertEdge(&listDirected, 3, 4, 50);

    AdjMat matrixDirected =
    {
        {INF, INF, INF, INF, INF},
        {1, INF, INF, INF, INF},
        {INF, 1, INF, INF, INF},
        {INF, 1, INF, INF, 1},
        {INF, INF, INF, INF, INF}
    };

    displayUndirectedMatrix(matrixUndirected);
    insertList(&linklist, listDirected);
   
   
    LL trav;
    printf("\nList of edges of an Undirected Graph:\n");
    for(trav = linklist;trav != NULL;trav = trav->link){
        printf(" (%d-%d) weight of %d,", trav->src, trav->des, trav->weight);
        printf(" \n");
    }

    return 0;
}

List* createNode(int vertex, int weight) {
    List* newNode = (List*)malloc(sizeof(List));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->link = NULL;
    return newNode;
}

void insertEdge(AdjList *list, int source, int destination, int weight) {
    List* newNode = createNode(destination, weight);
    newNode->link = list->LISTS[source];
    list->LISTS[source] = newNode;
}

void displayUndirectedMatrix(AdjMat A) {
    int src, des;
    for (src = 0; src < GSIZE; src++) {
        for (des = 0; des < GSIZE; des++) {
            if (A[src][des] == INF) {
                printf(" INF,");
            } else {
                printf(" %d,", A[src][des]);
            }
        }
        printf(" \n");
    }
}

void insertList(LL *A, AdjList B){
	int i;
	List *source;
	LL *trav, temp;
	
	for(i = 0; i < B.num_vertices; i++){
		for(source = B.LISTS[i]; source != NULL; source = source->link){
			temp = (LL)malloc(sizeof(struct node));
			temp->src = i;
			temp->des = source->vertex;
			temp->weight = source->weight;
			temp->link = NULL;
			
			for(trav = A; *trav != NULL && (*trav)->weight < temp->weight; trav = &(*trav)->link){}
				temp->link = *trav;
				*trav = temp;
		}
	}
}




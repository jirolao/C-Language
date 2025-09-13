#include <stdio.h>
#include <limits.h>

#define MAX 6
#define Z INT_MAX

enum { A, B, C, D, E, F };

typedef int MATRIX[MAX][MAX];

typedef struct {
    MATRIX M;
    int TotalCost;
} GRAPH;

typedef int SET[MAX];




GRAPH prims(MATRIX);
GRAPH kruskal(MATRIX);

int main(void) {
    MATRIX MAIN = { {Z, 1,  5,  4,  6,  5},
                    {1, Z,  5,  Z,  Z,  6},
                    {5, 5,  Z,  2,  Z,  Z},
                    {4, Z,  2,  Z,  1,  Z},
                    {6, Z,  Z,  1,  Z,  3},
                    {5, 6,  Z,  Z,  3,  Z} };

    GRAPH ror = kruskal(MAIN);
    GRAPH rar = prims(MAIN);
    printf("%d = %d", ror.TotalCost,rar.TotalCost);

    // printf("%d",prims(MAIN));

    return 0;
}

GRAPH prims(MATRIX main){
    GRAPH retval = {.TotalCost = 0};
    int SET[MAX] = {1,0,0,0,0,0};
    int edgeCTR = 0, head, end;

    while(edgeCTR < MAX-1){
        int small = Z, u  = 0, v = 0;
        for(head = 0; head < MAX; head++){
            if(SET[head]){
                for(end = 0; end < MAX; ++end){
                    if(SET[end] != 1 && main[head][end] < small){
                        small = main[head][end];
                        u = head;
                        v = end;
                    }
                }
            }
        }
        SET[v] = 1;

        if(small != Z){
            retval.M[u][v] = small;
            retval.TotalCost += small;
        }
     edgeCTR++;
    }
    return retval;
}

GRAPH kruskal(MATRIX main){

    int small, smallndy, smallndx, edgeCTR = 0;
    GRAPH retval = {.TotalCost = 0};

    int SET[MAX];
    int ndx;
    for(ndx = 0; ndx < MAX; ndx++){
        SET[ndx] = -1;
    }

    while(edgeCTR < MAX-1){
        small = Z;
		int ndx, ndy;
        //finds smallest edge amoang the graph
        for(ndx = 0; ndx < MAX; ndx++){
            for(ndy = ndx; ndy < MAX; ndy++){
                if(retval.M[ndx][ndy] != main[ndx][ndy] && main[ndx][ndy] < small){
                    small = main[ndx][ndy];
                    smallndx = ndx;
                    smallndy = ndy;
                }
            }
        }

        //checks if the 2 vertexes are different components
        int tempx = smallndx, tempy = smallndy;
        for(;SET[tempx] > 0;tempx = SET[tempx]){}
        for(;SET[tempy] > 0;tempy = SET[tempy]){}


        //Adds the info to the graph if it is not in the same component
        if(tempx != tempy){
            retval.TotalCost += small;
            retval.M[smallndx][smallndy] = retval.M[smallndy][smallndx] = small;
            edgeCTR++;

        //removes the vertex from main graph;
            // main[smallndx][smallndy] = Z;

        //Updates the Disjoint Set SET[]
            SET[smallndx] += SET[smallndy];
            SET[smallndy] = smallndx;
        }
    }
    return retval;
}



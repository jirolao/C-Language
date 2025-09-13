#include <stdio.h>

#define M_SIZE 4
#define INF 0xFF
typedef int MATRIX[M_SIZE][M_SIZE];

void initMat(MATRIX M);
void displayMat(MATRIX M);
void populateMat(MATRIX M);
void warshall(MATRIX dis, MATRIX costs);

int main(void){
    MATRIX m;
    initMat(m);
    displayMat(m);

    populateMat(m);
    displayMat(m);

    return 0;
}

void initMat(MATRIX M) {
    int x, y;
    for (x = 0; x < M_SIZE; x++) {
        for (y = 0; y < M_SIZE; y++) {
            M[x][y] = -1;
        }
    }
}

void displayMat(MATRIX M) {
    int x, y;
    for (x = 0; x < M_SIZE; x++) {
        printf("%d [ ", x);
        for (y = 0; y < M_SIZE; y++) {
            printf("%d", M[x][y]);
            if (y < M_SIZE - 1) {
                printf(", ");
            }
        }
        printf(" ]\n");
    }
    puts("");
}

void populateMat(MATRIX M) {
    MATRIX data = {
            {0, INF, -2, INF},
            {4, 0, 3, INF},
            {INF, INF, 0, 2},
            {INF, -1, INF, 0},
        };
    int x, y;
    for (x = 0; x < M_SIZE; x++) {
        for (y = 0; y < M_SIZE; y++) {
            warshall(M, data);
        }
    }
}

void warshall(MATRIX dis, MATRIX costs) {
    int x, y, z;
    // Inserting and setting up the matrix for the algorithm
    for (x = 0; x < M_SIZE; x++) {
        for (y = 0; y < M_SIZE; y++) {
            dis[x][y] = (costs[x][y] == INF) ? 0 : 1;
        }
    }

    for (x = 0; x < M_SIZE; x++) {
        dis[x][x] = 1;
    }

    displayMat(dis);

    for (x = 0; x < M_SIZE; x++) {
        for (y = 0; y < M_SIZE; y++) {
            for (z = 0; z < M_SIZE; z++) {
                if (dis[y][z] == 0) {
                    dis[y][z] = dis[y][x] & dis[x][z];
                }
            }
        }
    }
}
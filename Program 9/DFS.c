#include <stdio.h>
#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int n;


void DFS(int v) {
    int i;
    visited[v] = 1;
    printf("%d\n",v);

    for (i = 0; i < n; i++) {
        if (graph[v][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }


    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("DFS traversal: ");
    DFS(0);


    for (i = 0; i < n; i++) {
        if (visited[i] == 0) {
            printf("Graph is NOT connected\n");
            return 0;
        }
    }

    printf("Graph is CONNECTED\n");
    return 0;
}

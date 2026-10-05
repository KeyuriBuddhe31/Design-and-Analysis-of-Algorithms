#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int find(int *p, int x) {
    while (p[x] != x) x = p[x];
    return x;
}

void kruskalMST(int **cost, int V) {
    int min_cost = 0, edge_count = 0;
    int *parent = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) parent[i] = i;

    while (edge_count < V - 1) {
        int min = 9999, u = -1, v = -1;
        for (int i = 0; i < V; i++)
            for (int j = i + 1; j < V; j++)
                if (cost[i][j] < min && find(parent, i) != find(parent, j)) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
        if (u == -1) break;
        printf("Edge %d:(%d, %d) cost:%d\n", edge_count++, u, v, min);
        min_cost += min;
        parent[find(parent, u)] = find(parent, v);
    }
    printf("Minimum cost= %d\n", min_cost);
    free(parent);
}

int main() {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        cost[i] = (int *)malloc(V * sizeof(int));

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);

    kruskalMST(cost, V);

    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);

    return 0;
}

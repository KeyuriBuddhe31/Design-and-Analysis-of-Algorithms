#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void kruskalMST(int **cost, int V) {
	int *parent = (int *)malloc(V * sizeof(int));
	for (int i = 0; i < V; i++) {
		parent[i] = i;
	}
	int edge_count = 0;
	int min_cost = 0;
	while (edge_count < V - 1) {
		int min = 9999; 
		int u = -1, v = -1;
		for (int i = 0; i < V; i++) {
			for (int j = i + 1; j < V; j++) {
				if (cost[i][j] < min) {
					int root_i = i;
					while (parent[root_i] != root_i) {
						root_i = parent[root_i];
					}
				int root_j = j;
				while (parent[root_j] != root_j) {
				root_j = parent[root_j];
				}
				if (root_i != root_j) {
					min = cost[i][j];
					u = i;
					v = j;
					}
				}
			}
		}
		if (u != -1 && v != -1) {
			printf("Edge %d:(%d, %d) cost:%d\n", edge_count, u, v, min);
			min_cost += min;
			int root_u = u;
			while (parent[root_u] != root_u) {
				root_u = parent[root_u];
			}
			int root_v = v;
			while (parent[root_v] != root_v) {
				root_v = parent[root_v];
			}
			parent[root_u] = root_v;
			edge_count++;
		} else {
			break;
		}
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

#include <stdio.h>
#include <string.h>
#define INF 1000000000
int n;
int cost[20][20];
int memo[1 << 16][16];
int tsp(int mask, int u) {
	if (mask == (1 << n) - 1) {
		return (cost[u][0] != -1) ? cost[u][0] : INF;
	}
	if (memo[mask][u] != -1) {
		return memo[mask][u];
	}
	int minCost = INF;
	for (int v = 0; v < n; v++) {
		if (!(mask & (1 << v)) && cost[u][v] != -1) {
			int subCost = tsp(mask | (1 << v), v);
			if (subCost != INF) {
				int totalCost = cost[u][v] + subCost;
				if (totalCost < minCost) {
					minCost = totalCost;
				}
			}
		}
	}
	return memo[mask][u] = minCost;
}
int main() {
	if (scanf("%d", &n) != 1) return 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &cost[i][j]);
		}
	}
	memset(memo, -1, sizeof(memo));
	int ans = tsp(1, 0);

	if (ans >= INF) {
		printf("-1\n");
	} else {
		printf("%d\n", ans);
	}
	return 0;
}

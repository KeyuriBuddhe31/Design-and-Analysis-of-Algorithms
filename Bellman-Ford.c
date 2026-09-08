#include <stdio.h>
#include <limits.h>
#define INF LLONG_MAX
typedef long long ll;
typedef struct {
	int u, v;
	ll w;
} Edge;
int main() {
	int V, E;
	scanf("%d", &V);
	scanf("%d", &E);
	Edge edges[E];
	for (int i = 0; i < E; i++) {
		scanf("%d %d %lld", &edges[i].u, &edges[i].v, &edges[i].w);
	}
	int src;
	scanf("%d", &src);
	ll dist[V + 1];
	int parent[V + 1];
	for (int i = 1; i <= V; i++) {
		dist[i] = INF;
		parent[i] = -1;
	}
	dist[src] = 0;
	for (int i = 1; i <= V - 1; i++) {
		int updated = 0;
		for (int j = 0; j < E; j++) {
			int u = edges[j].u;
			int v = edges[j].v;
			ll w = edges[j].w;
			if (dist[u] != INF && dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				parent[v] = u;
				updated = 1;
			}
}

#include <stdio.h>
#include <limits.h>

#define V 5   // Number of vertices
#define E 8   // Number of edges

// Structure to represent an edge
struct Edge {
    int u, v, weight;
};

void bellmanFord(struct Edge edges[], int source) {
    int dist[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX; // Initialize all distances as infinity
    }
    dist[source] = 0;

    // Relax all edges (V-1) times
    for (int i = 1; i < V; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int weight = edges[j].weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int weight = edges[j].weight;

        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    // Print distances from source
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main() {
    struct Edge edges[] = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
        {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };
    int source = 0;
    
    bellmanFord(edges, source);
    return 0;
}

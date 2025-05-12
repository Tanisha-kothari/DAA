#include <stdio.h>
#include <limits.h>

#define V 4 // Number of vertices

// Function to implement Floyd-Warshall algorithm
void floydWarshall(int graph[V][V]) {
    int dist[V][V];

    // Initialize the distance matrix same as the input graph matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == 0 && i != j)
                dist[i][j] = INT_MAX; // No path
            else
                dist[i][j] = graph[i][j];
        }
    }

    // Apply the Floyd-Warshall algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distance matrix
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Example graph represented as adjacency matrix
    // 0 means no edge between vertices
    int graph[V][V] = {
        {0, 3, 0, 5},
        {3, 0, 1, 0},
        {0, 1, 0, 2},
        {5, 0, 2, 0}
    };

    // Call Floyd-Warshall algorithm
    floydWarshall(graph);

    return 0;
}

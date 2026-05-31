#include <stdio.h>

#define MAX 100 // Maximum number of vertices

int main() {
    // 1. Define the graph (6 vertices, 0 to 5) using an Adjacency Matrix
    int V = 6;
    int adj[MAX][MAX] = {0}; 
    int in_degree[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;
    int topo_order[MAX], count = 0;

    // Hardcoded directed edges: adj[src][dest] = 1
    adj[5][2] = 1;
    adj[5][0] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[1][3] = 1;

    // 2. Calculate in-degrees for all vertices
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j] == 1) {
                in_degree[j]++;
            }
        }
    }

    // 3. Enqueue all vertices with in-degree 0
    for (int i = 0; i < V; i++) {
        if (in_degree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // 4. Process the queue
    while (front < rear) {
        int u = queue[front++]; // Dequeue
        topo_order[count++] = u;

        // Reduce in-degree for all neighbors of u
        for (int v = 0; v < V; v++) {
            if (adj[u][v] == 1) {
                in_degree[v]--;
                // If in-degree becomes 0, add to queue
                if (in_degree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }

    // 5. Print the result
    if (count != V) {
        printf("Graph contains a cycle! Topological sort is not possible.\n");
    } else {
        printf("Topological Sort: ");
        for (int i = 0; i < count; i++) {
            printf("%d ", topo_order[i]);
        }
        printf("\n");
    }

    return 0;
}

#include <stdio.h>

#define MAX 100 // Maximum number of vertices

int main() {
 
    int V = 6;
    int adj[MAX][MAX] = {0}; 
    int in_degree[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;
    int topo_order[MAX], count = 0;

  
    adj[5][2] = 1;
    adj[5][0] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[1][3] = 1;

  
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j] == 1) {
                in_degree[j]++;
            }
        }
    }

 
    for (int i = 0; i < V; i++) {
        if (in_degree[i] == 0) {
            queue[rear++] = i;
        }
    }

    while (front < rear) {
        int u = queue[front++]; 
        topo_order[count++] = u;

        
        for (int v = 0; v < V; v++) {
            if (adj[u][v] == 1) {
                in_degree[v]--;
                
                if (in_degree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }

    
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

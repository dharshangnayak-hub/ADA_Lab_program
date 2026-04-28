#include <stdio.h>

#define V 4   // number of vertices
#define E 5   // number of edges

// Function to find parent (Union-Find without rank)
int findParent(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return findParent(parent, parent[i]);
}

// Function to perform union
void unionSet(int parent[], int x, int y) {
    int xset = findParent(parent, x);
    int yset = findParent(parent, y);
    parent[yset] = xset;
}

int main() {
    // Graph edges: {src, dest, weight}
    int edges[E][3] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    // Step 1: Sort edges by weight (simple bubble sort)
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j][2] > edges[j + 1][2]) {
                int temp0 = edges[j][0];
                int temp1 = edges[j][1];
                int temp2 = edges[j][2];
                edges[j][0] = edges[j + 1][0];
                edges[j][1] = edges[j + 1][1];
                edges[j][2] = edges[j + 1][2];
                edges[j + 1][0] = temp0;
                edges[j + 1][1] = temp1;
                edges[j + 1][2] = temp2;
            }
        }
    }

    // Step 2: Initialize parent array
    int parent[V];
    for (int i = 0; i < V; i++)
        parent[i] = i;

    printf("Edges in MST:\n");

    // Step 3: Pick edges one by one
    int count = 0;
    for (int i = 0; i < E && count < V - 1; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        int set_u = findParent(parent, u);
        int set_v = findParent(parent, v);

        if (set_u != set_v) {
            printf("%d -- %d == %d\n", u, v, w);
            unionSet(parent, set_u, set_v);
            count++;
        }
    }

    return 0;
}

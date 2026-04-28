
include <stdio.h>

int parent[10];

// Find parent (set)
int find(int i) {
    while(parent[i])
        i = parent[i];
    return i;
}

// Union of sets
int uni(int i, int j) {
    if(i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int n, cost[10][10];
    int i, j, min, mincost = 0;
    int a, b, u, v, ne = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }

    printf("\nEdges selected:\n");

    // Step: Repeat until n-1 edges are selected
    while(ne < n - 1) {
        min = 999;

        // Step: Find smallest edge
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                if(cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }

        // Step: Check for cycle
        u = find(u);
        v = find(v);

        // Step: If no cycle, include edge
        if(uni(u, v)) {
            printf("%d - %d = %d\n", a, b, min);
            mincost += min;
            ne++;
        }

        // Step: Remove edge
        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum cost = %d\n", mincost);
}

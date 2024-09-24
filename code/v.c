// DFS

#include <stdio.h>

int a[20][20], reach[20], n;

void dfs(int v)
{
    int i;
    reach[v] = 1; // Mark the current node as visited
    for (i = 1; i <= n; i++)
    {
        // If there is an edge between v and i and i is not visited yet
        if (a[v][i] && !reach[i])
        {
            printf("\n %d -> %d", v, i); // Print the edge
            dfs(i); // Recursively perform DFS
        }
    }
}

int main()
{
    int i, j, count = 0;
    
    printf("\nEnter number of vertices: ");
    scanf("%d", &n);

    // Initialize the adjacency matrix and reach array
    for (i = 1; i <= n; i++)
    {
        reach[i] = 0; // Initially, no vertices are visited
        for (j = 1; j <= n; j++)
            a[i][j] = 0; // Initialize the adjacency matrix with 0
    }

    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]); // Input the adjacency matrix
        }
    }

    // Perform DFS starting from vertex 1
    dfs(1);

    printf("\n");

    // Check how many vertices were visited
    for (i = 1; i <= n; i++)
    {
        if (reach[i])
            count++;
    }

    // Check if all vertices are reachable
    if (count == n)
        printf("\nThe graph is connected.\n");
    else
        printf("\nThe graph is not connected.\n");

    return 0;
}

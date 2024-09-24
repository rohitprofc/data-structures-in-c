// BFS

#include <stdio.h>
#include <stdlib.h>

#define initial 1
#define waiting 2
#define visited 3

int n, adj[100][100], state[100];
int queue[100], front = -1, rear = -1;

void create()
{
    int i, j;
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    // Initialize queue and state arrays
    for (i = 1; i <= n; i++)
    {
        queue[i] = 0;
        state[i] = initial;  // Initialize all vertices to initial state
    }

    printf("\nEnter graph data in adjacency matrix form:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
}

void insert(int vertex)
{
    if (rear == 99)
        printf("Queue Overflow\n");
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = vertex;
    }
}

int delete_queue()
{
    int deleted_item;
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    deleted_item = queue[front];
    front++;
    return deleted_item;
}

void BFS(int v)
{
    int i;
    insert(v);
    state[v] = waiting;

    while (!(front == -1 || front > rear))
    {
        v = delete_queue();
        printf("%d ", v);  // Print the visited node
        state[v] = visited;

        // Check adjacent vertices
        for (i = 1; i <= n; i++)
        {
            if (adj[v][i] == 1 && state[i] == initial)
            {
                insert(i);
                state[i] = waiting;
            }
        }
    }
    printf("\n");
}

void traversal()
{
    int v;
    printf("Enter the start vertex for BFS: ");
    scanf("%d", &v);

    // Perform BFS traversal starting from vertex v
    BFS(v);
}

int main()
{
    create();
    traversal();
    return 0;
}

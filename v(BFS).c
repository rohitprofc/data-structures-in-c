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
    printf("\n Enter the number of vertices:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        queue[i] = 0;
        state[i] = 0;
    }
    printf("\n Enter graph data in matrix form:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &adj[i][j]);
}
void insert(int vertex)
{
    if (rear == (100 - 1))
        printf("Queue Overflow\n");
    else
    {
        if (front == -1)
            front = 0;
        rear = rear + 1;
        queue[rear] = vertex;
    }
}
int delete_queue()
{
    int delete_item;
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    delete_item = queue[front];
    front = front + 1;
    return delete_item;
}
void BFS(int v)
{
    int i;
    insert(v);
    state[v] = waiting;
    while (!(front == -1 || front > rear))
    {
        v = delete_queue();
        printf("%d ", v);
        state[v] = visited;
        for (i = 0; i <= n; i++)
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
    for (v = 0; v <= n; v++)
        state[v] = initial;
    printf("Enter Start Vertex for BFS: \n");
    scanf("%d", &v);
    BFS(v);
}
int main()
{
    create();
    traversal();
    return 0;
}
/*
Output: -

 Enter the number of vertices:4

 Enter graph data in matrix form:
0 1 1 0
1 0 1 1
1 1 0 1
0 1 1 0
Enter Start Vertex for BFS:
4
4 2 3 1
*/
#include <stdio.h>
#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int n;

// DFS
void DFS(int vertex)
{
    int i;

    visited[vertex] = 1;
    printf("%d ", vertex);

    for (i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

// BFS
void BFS(int start)
{
    int queue[MAX];
    int front = 0, rear = 0;
    int i, vertex;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear] = start;
    rear++;
    visited[start] = 1;

    while (front < rear)
    {
        vertex = queue[front];
        front++;

        printf("%d ", vertex);

        for (i = 0; i < n; i++)
        {
            if (graph[vertex][i] == 1 && visited[i] == 0)
            {
                queue[rear] = i;
                rear++;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int edges, u, v, start, i;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");

    for (i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    // DFS
    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    DFS(start);

    // BFS
    printf("\nBFS Traversal: ");
    BFS(start);

    return 0;
}
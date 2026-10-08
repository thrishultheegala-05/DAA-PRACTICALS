#include <stdio.h>

#define MAX 100

int find(int parent[], int vertex) {
    if (parent[vertex] != vertex)
        parent[vertex] = find(parent, parent[vertex]);
    return parent[vertex];
}

void unionSets(int parent[], int u, int v) {
    int u_root = find(parent, u);
    int v_root = find(parent, v);
    parent[v_root] = u_root;
}

struct Edge {
    int u, v, weight;
};

void kruskal(struct Edge edges[], int n, int m) {
    int parent[MAX];
    struct Edge mst[MAX];
    int total_cost = 0, count = 0;

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        if (find(parent, u) != find(parent, v)) {
            mst[count++] = edges[i];
            total_cost += w;
            unionSets(parent, u, v);
        }

        if (count == n - 1) break;
    }

    printf("\nMinimum Spanning Tree edges:\n");
    for (int i = 0; i < count; i++) {
        printf("%d -- %d == %d\n", mst[i].u, mst[i].v, mst[i].weight);
    }
    printf("Total Cost of MST: %d\n", total_cost);
}

int main() {
    int n, m;
    struct Edge edges[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter each edge as: u v weight\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    kruskal(edges, n, m);

    return 0;
}

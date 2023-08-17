#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CITIES 20

// Structure to represent a Graph
struct Graph {
    int vertices;
    int adjMatrix[MAX_CITIES][MAX_CITIES];
};

// Function to initialize the graph
void initializeGraph(struct Graph *graph, int vertices) {
    graph->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest) {
    if (src >= 0 && src < graph->vertices && dest >= 0 && dest < graph->vertices) {
        graph->adjMatrix[src][dest] = 1;
    }
}

// Depth-First Search traversal
void dfs(struct Graph *graph, int node, bool visited[]) {
    visited[node] = true;
    printf("%d ", node);

    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjMatrix[node][i] == 1 && !visited[i]) {
            dfs(graph, i, visited);
        }
    }
}

// Breadth-First Search traversal
void bfs(struct Graph *graph, int startNode) {
    bool visited[MAX_CITIES] = {false};
    int queue[MAX_CITIES];
    int front = -1, rear = -1;

    visited[startNode] = true;
    queue[++rear] = startNode;

    while (front != rear) {
        int currentNode = queue[++front];
        printf("%d ", currentNode);

        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjMatrix[currentNode][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[++rear] = i;
            }
        }
    }
}

int main() {
    struct Graph graph;
    int n, source;

    printf("Enter the number of cities: ");
    scanf("%d", &n);

    initializeGraph(&graph, n);

    int edges;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (format: source destination):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(&graph, src, dest);
    }

    printf("Enter the starting city for traversal: ");
    scanf("%d", &source);

    printf("DFS traversal from %d: ", source);
    bool visited[MAX_CITIES] = {false};
    dfs(&graph, source, visited);
    printf("\n");

    printf("BFS traversal from %d: ", source);
    bfs(&graph, source);
    printf("\n");

    return 0;
}

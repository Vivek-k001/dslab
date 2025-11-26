#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adj[MAX];     // Adjacency list
int visited[MAX];   // Visited array
int queue[MAX];
int front = 0, rear = 0;

void enqueue(int v) {
    queue[rear++] = v;
}

int dequeue() {
    return queue[front++];
}

void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void bfs(int start) {
    for (int i = 0; i < MAX; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    printf("\nBFS Traversal: ");

    while (front < rear) {
        int node = dequeue();
        printf("%d ", node);

        Node* temp = adj[node];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                enqueue(temp->vertex);
                visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    int n, edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);   // For undirected graph
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    bfs(start);

    return 0;
}

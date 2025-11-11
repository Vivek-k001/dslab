#include <stdio.h>
#include <stdlib.h>

#define MAX 20

// Structure for adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Array of adjacency lists
struct Node* adjList[MAX];

// Visited array
int visited[MAX] = {0};

// Queue
int queue[MAX], front = -1, rear = -1;

// Function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Enqueue function
void enqueue(int v) {
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = v;
    }
}

// Dequeue function
int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    int v = queue[front];
    front++;
    return v;
}

// Add edge to the adjacency list
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    // For undirected graph, add the reverse edge too
    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

// BFS traversal
void BFS(int start, int n) {
    int i;
    enqueue(start);
    visited[start] = 1;

    printf("Breadth First Search traversal: ");
    while (front <= rear) {
        int current = dequeue();
        printf("%d ", current);

        struct Node* temp = adjList[current];
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                enqueue(adjVertex);
                visited[adjVertex] = 1;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, e, i, u, v, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency list
    for (i = 1; i <= n; i++)
        adjList[i] = NULL;

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v):\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    BFS(start, n);

    return 0;
}
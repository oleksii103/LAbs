#include <iostream>

const int N = 6;

int graph[N + 1][N + 1];
bool visited[N + 1];

void addEdge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void clearVisited() {
    for (int i = 1; i <= N; i++) {
        visited[i] = false;
    }
}

void DFS(int v) {
    visited[v] = true;
    std::cout << v << " ";

    for (int i = 1; i <= N; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

void BFS(int start) {
    int queue[N];
    int front = 0;
    int rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    while (front < rear) {
        int v = queue[front++];
        std::cout << v << " ";

        for (int i = 1; i <= N; i++) {
            if (graph[v][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
}

int main() {

    addEdge(1, 6);
    addEdge(6, 2);
    addEdge(2, 3);
    addEdge(3, 4);
    addEdge(6, 5);

    std::cout << "DFS (deep): ";
    DFS(1);

    clearVisited();

    std::cout << "\nBFS (width): ";
    BFS(1);

    return 0;
}
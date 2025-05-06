#include <bits/stdc++.h>
using namespace std;

// Global constants and variables
const int MAX_VERTICES = 100;
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

vector<int> adj[MAX_VERTICES];
int color[MAX_VERTICES];
int discovery[MAX_VERTICES];
int finish[MAX_VERTICES];
int dfs_time = 0;
int num_vertices;

void DFS_Visit(int u)
{
    color[u] = GRAY;
    dfs_time++;
    discovery[u] = dfs_time;

    for (int v : adj[u]) {
        if (color[v] == WHITE) {
            DFS_Visit(v);
        }
    }

    color[u] = BLACK;
    dfs_time++;
    finish[u] = dfs_time;
}

void DFS()
{
    for (int i = 0; i < num_vertices; i++) {
        color[i] = WHITE;
    }
    dfs_time = 0;
    for (int i = 0; i < num_vertices; i++) {
        if (color[i] == WHITE) {
            DFS_Visit(i);
        }
    }
}

int main()
{
    int m;
    cout << "Enter number of vertices and edges: ";
    cin >> num_vertices >> m;

    cout << "Enter " << m << " edges (u v) [0-based indexing]:\n";
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        // adj[v].push_back(u); // Uncomment if graph is undirected
    }

    DFS();

    cout << "\nDFS Results:\n";
    cout << "Vertex\tDiscovery\tFinish\n";
    for (int i = 0; i < num_vertices; ++i) {
        cout << i << "\t" << discovery[i] << "\t\t" << finish[i] << "\n";
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Depth-First Search function for topological sorting
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor])
            dfs(neighbor, adj, visited, st);
    }
    st.push(node); // push after visiting all neighbors (post-order)
}

// Function to perform Topological Sort using DFS
vector<int> topoSortDFS(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    stack<int> st;
    for (int i = 0; i < V; ++i) {
        if (!visited[i])
            dfs(i, adj, visited, st);
    }

    // Retrieve result from stack
    vector<int> topo;
    while (!st.empty()) {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);
    cout << "Enter the edges (u v) meaning u -> v:\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // directed edge from u to v
    }

    vector<int> topo = topoSortDFS(V, adj);

    cout << "Topological Sort Order:\n";
    for (int node : topo)
        cout << node << " ";
    cout << endl;

    return 0;
}
/*
5 2
5 0
4 0
4 1
2 3
3 1
*/

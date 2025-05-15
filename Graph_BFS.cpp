#include<bits/stdc++.h>
using namespace std;
void BFS(int source, vector<vector<int>>& adj)
{
    int n=adj.size();
    //Initialization
    vector<string>color(n,"write");
    vector<int>d(n,INT_MAX);
    vector<int>pred(n,-1); //predecessor
    //Initialize souece
    color[source] = "gray";
    d[source] = 0;
    queue<int>Q;
    Q.push(source);

    //BFS Loop
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int v:adj[u])
        {
            if(color[v]=="write")
            {
                color[v]="gray";
                d[v]=d[u]+1;
                pred[v]=u;
                Q.push(v);
            }
        }
        color[u]="black";
    }

cout << "\nResults from BFS:\n";
  cout << "\nVertex\tDistance\tPredecessor\n";
for (int i = 0; i < n; i++) {
    cout << "Node " << i << ": ";
    if (d[i] == INT_MAX) {
        cout << "Unreachable\n";
    } else {
        cout << "Distance = " << d[i];
        cout << ", Predecessor = ";
        if (pred[i] == -1) cout << "None";
        else cout << pred[i];
        cout << endl;
    }
}




}
int main(){

  int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n);

    cout << "Enter " << m << " edges (u v) [0-based indexing]:\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Remove this line for directed graph
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    BFS(source, adj);



return 0;
}

/*
Input:
6 7
0 1
0 3
1 2
1 4
2 5
4 5
3 4
0
*/
/*
#include <bits/stdc++.h>
using namespace std;

void BFS(int start_node, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;
    visited[start_node] = true;
    q.push(start_node);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int a : adj[node]) {
            if (!visited[a]) {
                visited[a] = true;
                q.push(a);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1); // 1-based indexing

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // remove if directed
    }

    vector<bool> visited(n + 1, false);
    int start;
    cin >> start;

    cout << "BFS traversal starting from node " << start << ": ";
    BFS(start, adj, visited);
    cout << endl;

    return 0;
}
*/
/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, vector<vector<pair<int, int>>>& graph, vector<bool>& visited) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (auto [neighbor, weight] : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n);
    vector<bool> visited(n, false);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // If undirected
    }

    int start;
    cin >> start;
    bfs(start, graph, visited);

    return 0;
}
*/

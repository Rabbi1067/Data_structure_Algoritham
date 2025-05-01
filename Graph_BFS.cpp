#include<bits/stdc++.h>
using namespace std;
void BFS(int source, vector<vector<int>>& adj)
{
    int n=adj.size();
    //Initialization
    vector<string>color(n,"write");
    vector<int>d(n,INT_MAX);
    vector<int>pred(n,-1);
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

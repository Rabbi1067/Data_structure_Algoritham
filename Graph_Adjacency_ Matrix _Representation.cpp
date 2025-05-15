//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
void addEdges(vector<vector<int>>&adj,int i,int j,int weight)
{
    adj[i][j]=weight;
    adj[j][i]=weight;// jodi directed graph hoi tahole weight hobe na & adj[j][i]=weight at bad jabe
}
void deleteEdges(vector<vector<int>>&adj,int i,int j)
{
    adj[i][j]=0;
    adj[j][i]=0;
}
void searchEdge(const vector<vector<int>>& adj, int u, int v) {
    if (adj[u][v] != 0) {
        cout << "Edge exists between " << u << " and " << v
             << " with weight: " << adj[u][v] << endl;
    } else {
        cout << "No edge exists between " << u << " and " << v << endl;
    }
}
void print(vector<vector<int>>&adj)
{
    int n=adj.size();
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<adj[i][j]<< "  ";
        }
        cout<<endl;
    }
}
int main() {
    int v, e;
    cout << "Enter number of Vertices: ";
    cin >> v;
    cout << "Enter number of Edges: ";
    cin >> e;

    vector<vector<int>> adj(v, vector<int>(v, 0)); // Initialize once

    while (true) {
        int n;
        cout << "\nMenu:\n1. Add edges\n2. Print matrix\n3. Delete edge\n4. searchEdge\n5. Exit\nChoice: ";
        cin >> n;

        if (n == 1) {
            cout << "Enter each edge as: vertex1 vertex2 weight" << endl;
            for (int i = 0; i < e; i++) {
                int u, v, w;
                cin >> u >> v >> w;
                addEdges(adj, u, v, w);
            }
        } else if (n == 2) {
            cout << "\nAdjacency Matrix Representation (with weight):" << endl;
            print(adj);
            /*
             for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<vertices;j++)
            cout<<setw(3)<<adjmat[i][j]<<" ";
        cout<<endl;
    }
    */
        } else if (n == 3) {
            int del_u, del_v;
            cout << "\nEnter edge to delete (vertex1 vertex2): ";
            cin >> del_u >> del_v;
            deleteEdges(adj, del_u, del_v);
        } else if (n == 4) {
          int u, v;
            cout << "Enter vertices to search edge (vertex1 vertex2): ";
            cin >> u >> v;
            searchEdge(adj, u, v);
        } else {
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
/*
5
6
1 0 2
0 2 3
1 2 15
1 3 2
3 4 9
2 4 13
2

*/



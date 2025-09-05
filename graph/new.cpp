#include<bits/stdc++.h>
#include <vector>
using namespace std;
int main(){
    int vertices, edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edges;

    vector<pair<int,int>>adj[vertices];
    int u,v,weight;
    for(int i=0; i<edges; i++){
        cin >> u >> v>> weight;
        adj[u].push_back({v,weight});
        adj[v].push_back({u,weight});
        
    }
    for(int i=0; i<vertices; i++){
        cout << i << " -> ";
        for(int j=0; j<adj[i].size(); j++){
            cout << adj[i][j].first<<" "<<adj[i][j].second << " ";
        }
        cout << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;

///.........Graph.........///
vector <int> adj[10000000];
int X[] = {1, -1, 0, 0};
int Y[] = {0, 0, 1, -1};

void bfs (int n, int source)
{
    bool vis[n+1] = {0};
    vis[source] = 1;
    queue <int> q;
    q.push(source);
    
    int node;
    vector <int> travers;
    while (!q.empty()){
        node = q.front();
        q.pop();
        travers.push_back(node);

        for (int child:adj[node]){
            if (!vis[child]){
                vis[child] = 1;
                q.push(child);
            }
        }  
    }
    cout<<travers.size();
}

int main()
{
    int n, s;
    cin>>n>>s;

    int u, v;
    for (int i = 0; i < n; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(n, s);

    return 0;
}

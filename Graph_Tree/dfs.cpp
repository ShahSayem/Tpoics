#include <bits/stdc++.h>
using namespace std;

const int MAX = 10000000+5;

///.........Graph.........///
vector <int> adj[MAX];
vector <int> travers;
bool vis[MAX];
int X[] = {1, -1, 0, 0};
int Y[] = {0, 0, 1, -1};

void dfs(int node)
{
    vis[node] = 1;
    travers.push_back(node);
    for (auto child: adj[node]){
        if (!vis[child])
            dfs(child);
    }
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

    dfs(s);

    for (int i = 0; i < travers.size(); i++){
        cout<<travers[i]<<" ";
    }

    return 0;
}

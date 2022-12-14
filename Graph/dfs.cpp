#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long double pi = 3.14159265358979323846;
const ll MOD = 1e9+7;
const int MAX = 10000000;

///.........Graph.........///
vector <int> adj[10000000];
vector <int> travers;
bool vis[10000000] = {0};
int X[] = {1, -1, 0, 0};
int Y[] = {0, 0, 1, -1};

void dfs(int node)
{
    vis[node] = 1;
    travers.push_back(node);
    for (auto child: adj[node]){
        if (!vis[child]){
            dfs(child);
        }
    }
}

void solve()
{
    int n, s;
    cin>>n>>s;

    int u, v;
    for (int i = 0; i < n; i++){
        cin>>u>>v;
        
    }

    dfs(s);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int t;
    // cin>>t;
    // while (t--){
        solve();
        cout<<"\n";
    // }

    for (int i = 0; i < travers.size(); i++){
        cout<<travers[i]<<" ";
    }

    return 0;
}

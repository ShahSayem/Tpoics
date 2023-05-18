#include <bits/stdc++.h>
using namespace std;

//By Errichto
#define Shah_Sayem ios_base::sync_with_stdio(false);cin.tie(NULL);
const int MAX = 1000005;
int LOG;
vector <int> adj[MAX];
int parent[MAX][21];
int depth[MAX];

void dfs(int node, int p)
{
    depth[node] = depth[p]+1;
    parent[node][0] = p;
    for(int i = 1; i < LOG; i++){
        parent[node][i] = parent[ parent[node][i-1] ][i-1];
    }

    for (int child: adj[node]){
        if (child != p)
            dfs(child, node);
    }
}

int getLCA(int a, int b)    //O(N)
{
    if (depth[a] < depth[b]){
        swap(a, b);
    }

    while (depth[a] > depth[b]){
        a = parent[a][0];
    }
    
    
    if (a == b)
        return a;

    while (a != b){
        a = parent[a][0];
        b = parent[b][0];
    }

    return a;   //Here, parent[a][0] = parent[b][0]
}

int main()
{
    Shah_Sayem

    int n, m, v;
    cin>>n;

    while((1 << LOG) <= n)
        LOG++;

    for (int i = 1; i <= n; i++){
        cin>>m;
        while (m--){
            cin>>v;
            v++;

            adj[i].push_back(v);
            adj[v].push_back(i);
        } 
    }
    dfs(1, 0);

    int q, a, b, x;
    cin>>q;
    while (q--){
        cin>>a>>b;
        a++, b++;

        x = getLCA(a, b);
        x--;

        cout<<x<<"\n";
    }
    
    return 0;
}

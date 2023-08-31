#include <bits/stdc++.h>
using namespace std;

#define Shah_Sayem ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

//Problem: https://www.codechef.com/problems/REVERSE

///.........Graph.........///
const int MAX = 1e5+5;
             //v    w
vector < pair<int, int> > adj[MAX];
vector <int> level(MAX, INT_MAX);
int n ,m;

int bfs (int source)
{
    deque <int> dq;
    dq.push_back(source);
    level[source] = 0;

    int node, ans;
    while (!dq.empty()){
        node = dq.front();
        dq.pop_front();

        int childVar, weight;
        for (auto child:adj[node]){
            childVar = child.first;
            weight = child.second;

            if (level[node]+weight < level[childVar]){
                level[childVar] = level[node]+weight;
                
                if (weight == 1){
                    dq.push_back(childVar);
                }
                else {
                    dq.push_front(childVar);
                }
            }
        }  
    }

    if (level[n] == INT_MAX)
        ans = -1;
    else 
        ans = level[n];

    return ans;
}

int main()
{
    Shah_Sayem
    #ifndef ONLINE_JUDGE
        freopen("Input.txt", "r", stdin);
        freopen("Output.txt", "w", stdout);
        freopen("Error.txt", "w", stderr);
    #endif

    cin>>n>>m;

    int u, v;
    for (int i = 0; i < m; i++){
        cin>>u>>v;

        if (u == v)
            continue;

        adj[u].push_back({v, 0});
        adj[v].push_back({u, 1});
    }

    cout<<bfs(1);

    return 0;
}

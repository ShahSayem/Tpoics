#include <bits/stdc++.h>
using namespace std;

class DisjointSet 
{
    vector <int> rank, parent, sz;
public:
    DisjointSet(int n){
        rank.resize(n+1, 0); //1 base indexing
        parent.resize(n+1);
        sz.resize(n+1);
        for (int i = 0; i <= n; i++){
            parent[i] = i;
            sz[i] = 1;
        } 
    }

    int findUltPar(int node){
        if (node == parent[node])
            return node;
        
        return parent[node] = findUltPar(parent[node]);
    }

    void unionByRank(int u, int v){     //union By Rank
        int ultParU = findUltPar(u);
        int ultParV = findUltPar(v);

        if (ultParU == ultParV)
            return;

        if (rank[ultParU] < rank[ultParV])
            parent[ultParU] = ultParV;
        else if (rank[ultParV] < rank[ultParU])
            parent[ultParV] = ultParU;
        else {
            parent[ultParU] = ultParV;
            rank[ultParU]++;
        }
    }

    void unionBySize(int u, int v){        //union By Size
        int ultParU = findUltPar(u);
        int ultParV = findUltPar(v);

        if (ultParU == ultParV)
            return;
        if (sz[ultParU] < sz[ultParV]){
            parent[ultParU] = ultParV;
            sz[ultParV] += sz[ultParU];
        }
        else {
            parent[ultParV] = ultParU;
            sz[ultParU] += sz[ultParV];
        }
    }
};


int main()
{
    int n, x, y;
    cin>>n;
    DisjointSet ds(n);

    // for (int i = 0; i < n; i++){     //union By Rank
    //     cin>>x>>y;
    //     ds.unionByRank(x, y);

    //     if (ds.findUltPar(3) == ds.findUltPar(7)){
    //         cout<<3<<" and "<<7<<" have Same parent\n";
    //     }
    //     else {
    //         cout<<3<<" and "<<7<<" don't have Same parent\n";
    //     }
    // }

    for (int i = 0; i < n; i++){    //union By Size
        cin>>x>>y;
        ds.unionBySize(x, y);

        if (ds.findUltPar(3) == ds.findUltPar(7)){
            cout<<3<<" and "<<7<<" have Same parent\n";
        }
        else {
            cout<<3<<" and "<<7<<" don't have Same parent\n";
        }
    }

    return 0;
}

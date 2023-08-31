#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector <ll> dijkstra(int n, vector < vector <ll> > adj[], int s)
{
    priority_queue < pair<ll, int>, vector <pair<ll, int>>, greater<pair<ll, int>> > pq;
    vector <ll> distTo(n, LONG_LONG_MAX);
    distTo[s] = 0;
    pq.push({0, s});

    int node;
    ll dis;
    while (!pq.empty()){
        node = pq.top().second;
        dis = pq.top().first;
        pq.pop();

        int v;
        ll w;
        for (auto it : adj[node]){
            v = it[0];
            w = it[1];

            if (dis+w < distTo[v]){
                distTo[v] = dis+w;
                pq.push({distTo[v], v});
            }
        }  
    }

    return distTo; 
}

int main()
{
      //numOfNode
    int n = 6, s = 0; 
    vector < vector <ll> > adj[n];
                 //node, weight
    adj[0].push_back({1, 4});
    adj[0].push_back({2, 4});
    adj[1].push_back({0, 4});
    adj[1].push_back({2, 2});
    adj[2].push_back({0, 4});
    adj[2].push_back({1, 2});
    adj[2].push_back({3, 3});
    adj[2].push_back({4, 1});
    adj[2].push_back({5, 6});
    adj[3].push_back({2, 3});
    adj[3].push_back({5, 2});
    adj[4].push_back({2, 1});
    adj[4].push_back({5, 3});
    adj[5].push_back({2, 6});
    adj[5].push_back({3, 2});
    adj[5].push_back({4, 3});

    vector <ll> ans = dijkstra(n, adj, s);
    for (auto it : ans){
        cout<<it<<" ";
    }
    
    return 0;
}

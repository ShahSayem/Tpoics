#include <bits/stdc++.h>
using namespace std;


vector <int> dijkstra(int v, vector < vector <int> > adj[], int s)
{
    priority_queue < pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>> > pq;
    vector <int> distTo(v, INT_MAX);
    distTo[s] = 0;
    pq.push({0, s});

    int node, dis;
    while (!pq.empty()){
        node = pq.top().second;
        dis = pq.top().first;
        pq.pop();

        for (auto it : adj[node]){
            int v = it[0];
            int w = it[1];

            if (dis+w < distTo[v]){
                distTo[v] = dis+w;
                pq.push({dis+w, v});
            }
        }  
    }

    return distTo; 
}

int main()
{
    int v = 3, e = 3, s = 2; 
    vector < vector <int> > adj[v];
    adj[0].push_back({1, 1});
    adj[0].push_back({2, 6});
    adj[1].push_back({2, 3});
    adj[1].push_back({0, 1});
    adj[2].push_back({1, 3});
    adj[2].push_back({0, 6});

    vector <int> ans = dijkstra(v, adj, s);
    for (auto it : ans){
        cout<<it<<" ";
    }
    
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

vector <int> dijkstra(int n, vector < vector <int> > adj[], int s)
{
    priority_queue < pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>> > pq;
    vector <int> distTo(n, INT_MAX);
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
    vector < vector <int> > adj[n];
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

    vector <int> ans = dijkstra(n, adj, s);
    for (auto it : ans){
        cout<<it<<" ";
    }
    
    return 0;
}

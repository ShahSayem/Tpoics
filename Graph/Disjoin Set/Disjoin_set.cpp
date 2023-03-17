#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define Shah_Sayem ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

const ll MOD = 1e9+7;
const int MAX = 100000+5;
int par[MAX], circle[MAX];

int Find (int x){
    if (par[x] = x){
        return x;
    }

    par[x] = Find(par[x]);

    return par[x];
}

void Union(int u, int v)
{
    int repU = Find(u); 
    int repV = Find(v); 

    if (repU == repV){
        cout<<circle[repU]<<"\n";
    }
    else {
        circle[repU] += circle[repV];
        par[v] = u;

        cout<<circle[repU]<<"\n";
    }
}

void solve()
{
    int n, u, v, num = 1;
    cin>>n;

    string s1, s2;
    map <string, int> mp;
    for (int i = 0; i < MAX; i++){
        par[i] = i;
        circle[i] = 1;
    }
    for (int i = 0; i < n; i++){
        cin>>s1>>s2;

        if (mp.find(s1) == mp.end()){
            mp[s1] = num++;
        }
        if (mp.find(s2) == mp.end()){
            mp[s2] = num++;
        }
        Union(mp[s1], mp[s2]);
    }
    
    //cout<<par[3]<<"\n";
}

int main()
{
    Shah_Sayem

    int t = 1;
    cin>>t;
    while (t--){
        solve();
    }

    return 0;
}

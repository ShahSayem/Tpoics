#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000+5;
int par[MAX], circle[MAX];

int Find (int x){          //Incomplete -> LU ACM
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

int main()
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

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin>>n;

    vector <int> cnt(n+1, 0), divCount(n+1, 0);
    for (int i = 0; i < n; i++){
        cin>>x;

        cnt[x]++;
    }

    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j+=i){
            divCount[j] += cnt[i];
        }  
    }    
    
    for (auto it : divCount){
        cout<<it<<" ";
    }
    

    return 0;
}

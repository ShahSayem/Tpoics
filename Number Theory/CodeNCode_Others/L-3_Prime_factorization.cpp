#include <bits/stdc++.h>
#define   ll   long long
using namespace std;

const ll MX = 10e15;
vector <ll> v;

void solve()
{
    ll n;
    cin>>n;

    for (ll i = 2; i*i <= n; i++){
        while (n%i == 0){
            cout<<i<<" ";
            n /= i;
        }           
    }

    if (n>1)
        cout<<n;       
}

int main()
{
    int t;
    cin>>t;

    while (t--){
        solve();
        cout<<endl;     
    }
    
    return 0;
}
    
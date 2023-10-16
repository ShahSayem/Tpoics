//Shah Sayem
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
const int MAX = 10000000;


ll getExp(ll a, ll b)  //can be used in BigMod
{
    if (b == 0)
        return 1;
    if (b%2 == 0){
        auto x = getExp(a, b/2)%MOD;
        return (x*x)%MOD;
    }
    return (a * getExp(a, b-1))%MOD;
}  

int main()
{
    ll a, b;
    cout<<"Enter a, b to get (a^b)%MOD: ";
    cin>>a>>b;
    cout<<getExp(a, b);

    return 0;
}



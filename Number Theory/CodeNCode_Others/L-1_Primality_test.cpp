#include <bits/stdc++.h>
#define   ll   long long
using namespace std;


bool primeChecker (ll n)
{
    if(n==0 || n==1)
        return false;
    for (int i = 2; i*i <= n; i++){
        if (n%i == 0)
            return false;
    }
    return true;
}

int main()
{
    ll n;
    cin>>n;

    cout<<primeChecker(n);
    
    return 0;
}
    
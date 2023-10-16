#include <bits/stdc++.h>
using namespace std;

#define Shah_Sayem ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;
const ll MOD = 1e9+7;
const int MAX = 1e7+5;


void nCr(ll n, ll r)  //Combination
{
    ll p= 1, k=1, m;
    if (n - r < r)  r = n - r;
    if (r != 0)
    {
        while(r)
        {
            p*=n, k*=r;
            m=__gcd(p, k);
            p/=m, k/=m;
            n--, r--;
        }
    }
    else p=1;
    cout<<p<<endl;
}

ll fact(ll n)
{
      if(n <= 1) return 1;
      return n * fact(n - 1);
}
ll nPr(ll n, ll r) //permutation
{
      return fact(n) / fact(n - r);
} 

int main()
{
       ll n, r;
       cin>>n>>r;
       cout<<nPr(n, r);

       return 0;
}


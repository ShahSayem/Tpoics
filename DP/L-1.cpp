#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define Shah_Sayem ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

const long double pi = 3.14159265358979323846;
const ll MOD = 1e9+7;
const int MAX = 10000000;

int dp[MAX];
///.........Graph.........///
//vector <int> adj[10000000];
int X[] = {1, -1, 0, 0};
int Y[] = {0, 0, 1, -1};

//Top-Down or Memoisation
int fib(int n)
{
    if (n <= 1){
        dp[n] = n;

        return dp[n];
    }
    
    if (dp[n] == -1)
        dp[n] =  fib(n-1)+fib(n-2);

    return dp[n];
}

int main()
{
    Shah_Sayem

    memset(dp, -1, sizeof(dp));

    int n;
    cin>>n;

    cout<<fib(n)<<"\n";

    // Bottom up or Tabulation
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    cout<<dp[n];

    return 0;
}

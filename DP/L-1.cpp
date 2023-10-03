#include <bits/stdc++.h>
using namespace std;

#define Shah_Sayem ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;
const ll MOD = 1e9+7;
const int MAX = 10000000;
int dp[MAX];


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

    cout<<"From Top-Down or Memoisation: ";
    cout<<fib(n)<<"\n";


    // Bottom up or Tabulation
    cout<<"From Tabulation: ";
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    cout<<dp[n]<<"\n";

    int prev = 1, prev2 = 0, currFib;
    if (n == 0 || n == 1){
        currFib = n;
    }

    //Memory optimised Bottom up or Tabulation
    cout<<"From memory optimised Tabulation: ";
    for (int i = 2; i <= n; i++){
        currFib = prev + prev2;

        prev2 = prev;
        prev = currFib;
    }
    cout<<currFib<<"\n";

    return 0;
}

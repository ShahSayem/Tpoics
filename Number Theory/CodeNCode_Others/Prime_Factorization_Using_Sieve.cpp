#include <bits/stdc++.h>
#define   ll   long long
using namespace std;

const int MAX = 1000000;
// Prime Factorization using Sieve algorithm: 	 		=> O(log(n))
// Ex: 50 =>  2  5  5
vector<int> spf(MAX); // SPF : smallest prime factor
void sieve()               // => O( nloglogn)
{
    for (int i = 1; i < MAX; i++)  
        spf[i] = i;

    for (int i = 2; i * i < MAX; i++){
        if (spf[i] == i){
            for (int j = i * i; j < MAX; j += i)
                  if (spf[j] == j) spf[j] = i;
        }
    }
}
int main()
{
    sieve();

    int n;
    cin >> n;

    while (n != 1){
        cout << spf[n] << " ";
        n /= spf[n];
    }
}

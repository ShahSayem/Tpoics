#include <bits/stdc++.h>
using namespace std;

#define Shah_Sayem ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;
const ll MOD = 1e9+7;
const int MAX = 1e7+5;

ll gcd(ll a, ll b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<int> v(m);
    for (int i = 0; i < m; i++){
        cin >> v[i];
        if (v[i] == 1){
            cout << 0 << endl;
            return;
        }
    }
    long long ans = 0;
    for (int i = 1; i < (1 << m); i++){ // loop from 1 to 2^m
        vector<int> subset;
        int cnt = 0;
        for (int j = 0; j < m; j++){ // loop through binary representation of number(1 to 2^n)
            if (i & (1 << j)){ // checking ith bit is set(1) or not
                subset.push_back(v[j]);
                cnt++;
            }
        }
        int NumOfDiv, lcm = 1;
        for (auto it : subset) lcm = lcm * it / (gcd(lcm, it));
        NumOfDiv = n / lcm;
        if (cnt & 1) // principle of inclusion and exclution(A U B U C = n(A) + n(B) + n(C)-n(AUB)-n(AUC)-n(BUC)+n(AUBUC));
              ans += NumOfDiv;
        else ans -= NumOfDiv;
    }
    cout << n - ans << endl;
}


int main()
{


    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int BASE = 131; // to avoid collision we use a prime grater than current base (base is 128 as we are including lower-upper case & numbers)
const int MAX = 1000005;
const int MOD = 1000000007;

ll h[MAX+5], power[MAX+5];

//From Sadman Sakib Vai, DevSkill B13

void generatePrefixHash(string &s)
{
    h[0] = s[0]; // storing ascii value
    for (int i = 1; i < s.size(); i++){
        h[i] = ((h[i-1]*BASE) + s[i]) % MOD;
    }

    power[0] = 1; //power[x] = power[x-1]*BASE
    for (int i = 1; i <= s.size(); i++){
        power[i] = (power[i-1]*BASE) % MOD;
    }
}

ll generateHash(string &s)
{
    ll H = 0;
    for (auto c: s)
        H = (H*BASE + c) % MOD;

    return H;
}

ll getHash(int l, int r) // hash(s[l...r]) --> s = "aabccd" --> getHash(0, 3) = HashOf(aabc)
{
    if (l == 0)
        return h[r];

    return (h[r]-(h[l-1] * power[r-l+1]%MOD) + MOD) % MOD;
}

int main()
{    
    string s1, s2;
    // cout<<"Enter two srting to know whether they equal or not: ";
    cin>>s1>>s2;
    int n = s1.size(), m = s2.size();

    generatePrefixHash(s1);

    ll hashOfS2 = generateHash(s2);
    // cout<<"positions: ";
    for (int i = 0; i <= n-m; i++){ //O(n)
        if (getHash(i, i+m-1) == hashOfS2){
            cout<<i<<" ";
        }
    }
    cout<<"\n";

    return 0;
} 
  

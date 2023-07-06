#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1000005;
const int BASE1 = 137, BASE2 = 277; // to avoid collision we use a prime grater than current base (base is 128 as we are including lower-upper case & numbers)
const int MOD1 = 127657753, MOD2 = 987654319;
#define Shah_Sayem ios_base::sync_with_stdio(false);cin.tie(NULL);

//From Sadman Sakib Vai, DevSkill B13
//and YouKnowWho
// collusion rate = 1 / MOD; if i use double hashing collusion rate will be 1 / (MOD1 * MOD2);
// const __int128 MOD = 202206214218227; // More efficient module for the __int128 datatype

struct two
{
    ll f, s;
};

bool isEqual(const two& x, const two& y) {
    return (x.f == y.f && x.s == y.s);
}

vector <two> sh, power;

vector <two> generateExponents(int n)
{
    vector <two> power(n+1);
    //For first hash
    power[0].f = 1;
    for (int i = 1; i <= n; i++){
        power[i].f = (power[i-1].f*BASE1) % MOD1;
    }

    //For second hash
    power[0].s = 1;
    for (int i = 1; i <= n; i++){
        power[i].s = (power[i-1].s*BASE2) % MOD2;
    }

    return power;
}

vector <two> generatePrefixHash(string &s)
{
    vector <two> h(s.size());
    //For first hash
    h[0].f = s[0]; // storing ascii value
    for (int i = 1; i < s.size(); i++){
        h[i].f = ((h[i-1].f*BASE1) + s[i]) % MOD1;
    }

    //For second hash
    h[0].s = s[0]; // storing ascii value
    for (int i = 1; i < s.size(); i++){
        h[i].s = ((h[i-1].s*BASE2) + s[i]) % MOD2;
    }

    return h;
}

two generateHash(string &s)
{
    two H = {0, 0};
    for (auto c: s)
        H.f = (H.f*BASE1 + c) % MOD1;

    for (auto c: s)
        H.s = (H.s*BASE2 + c) % MOD2;

    return H;
}

two getHash(int l, int r, vector <two> &h) // hash(s[l...r]) --> s = "aabccd" --> getHash(0, 3) = HashOf(aabc)
{
    if (l == 0)
        return h[r];

    ll first = (h[r].f-(h[l-1].f * power[r-l+1].f%MOD1) + MOD1) % MOD1;
    ll second = (h[r].s-(h[l-1].s * power[r-l+1].s%MOD2) + MOD2) % MOD2;

    return {first, second};
}


int main()
{   
    Shah_Sayem

    string s1, s2;
    cin>>s1>>s2;
    int n, m;
    n = s1.size();
    m = s2.size();

    sh = generatePrefixHash(s1);
    power = generateExponents(n);
    two hashOfS2 = generateHash(s2);

    for (int i = 0; i <= n-m; i++){
        if (isEqual(getHash(i, i+m-1, sh), hashOfS2))
            cout<<i<<" ";
    }

    return 0;
} 
  
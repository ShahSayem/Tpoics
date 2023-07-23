#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1000005;
const int BASE1 = 137, BASE2 = 277; // to avoid collision we use a prime grater than current base (base is 128 as we are including lower-upper case & numbers)
const int MOD1 = 127657753, MOD2 = 987654319;
#define Shah_Sayem ios_base::sync_with_stdio(false);cin.tie(NULL);

//From Sadman Sakib Vai, DevSkill B13
//and YouKnowWho
// collusion rate = 1 / MOD; if i use double hashing collusion rate will be 1 / (MOD1 * MOD2) for each hash call;
// const __int128 MOD = 202206214218227; // More efficient module for the __int128 data type

vector < pair<int, int> > sh, rsh, power;

void generateExponents(int n)
{
    power.resize(n+1);
    power[0].first = 1;
    for (int i = 1; i <= n; i++){
        power[i].first = (1LL*power[i-1].first*BASE1) % MOD1;
    }

    power[0].second = 1;
    for (int i = 1; i <= n; i++){
        power[i].second = (1LL*power[i-1].second*BASE2) % MOD2;
    }
}

void generatePrefixHash(string &s)
{
    int n = s.size();
    sh.resize(n);
    sh[0].first = s[0]; // storing ascii value
    for (int i = 1; i < n; i++){
        sh[i].first = ((1LL*sh[i-1].first*BASE1) + s[i]) % MOD1;
    }

    sh[0].second = s[0]; // storing ascii value
    for (int i = 1; i < n; i++){
        sh[i].second = ((1LL*sh[i-1].second*BASE2) + s[i]) % MOD2;
    }
}

pair<ll, ll> generateHash(string &s)
{
    pair<ll, ll> H = {0, 0};
    for (auto c: s)
        H.first = (H.first*BASE1 + c) % MOD1;

    for (auto c: s)
        H.second = (H.second*BASE2 + c) % MOD2;

    return H;
}

pair<int, int> getHash(int l, int r, vector < pair<int, int> > &h) // hash(s[l...r]) --> s = "aabccd" --> getHash(0, 3) = HashOf(aabc)
{
    if (l == 0)
        return h[r];

    int f = (h[r].first-(1LL*h[l-1].first * power[r-l+1].first%MOD1) + MOD1) % MOD1;
    int s = (h[r].second-(1LL*h[l-1].second * power[r-l+1].second%MOD2) + MOD2) % MOD2;

    return {f, s};
}

int main()
{   
    Shah_Sayem

    string s1, s2;
    cin>>s1>>s2;
    int n, m;
    n = s1.size();
    m = s2.size();

    generatePrefixHash(s1);
    generateExponents(n);
    pair<int, int> hashOfS2 = generateHash(s2);
    pair<int, int> hashOfS1 = generateHash(s1);

    for (int i = 0; i <= n-m; i++){
        if (getHash(i, i+m-1, sh) == hashOfS2)
            cout<<i<<" ";
    }

    // cout<<hashOfS1.first<<" "<<hashOfS1.second<<"\n";
    // cout<<hashOfS2.first<<" "<<hashOfS2.second<<"\n";

    return 0;
} 
  
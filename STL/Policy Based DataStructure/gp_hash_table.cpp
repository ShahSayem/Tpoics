#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

int main()
{
    int n, k;
    cin>>n;

    char ch;
    gp_hash_table <char, int> gph; // SAME AS unordered_map; But, More Faster;
                                   // 3-6x faster insertion/deletion and 4-10x increase for writes/reads
    for (int i = 0; i < n; i++){
        cin >> ch >> k;
        gph[ch] = k;
    }

    for (auto i: gph){
        cout<<i.first<<" "<<i.second<<"\n";
    }
    cout<<"\n";

    int idx = gph.find('S')->second;
    cout<<idx<<"\n";

    return 0;
}
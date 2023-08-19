#include <bits/stdc++.h>
using namespace std;

int printSSHavingKsum(int idx, vector <int> &v, int sum, int k)
{
    if (idx == v.size()){   //condition satisfied
        if (sum == k){
            return 1;
        }

        return 0;   //condition not satisfied
    }

    //Pick
    sum += v[idx];
    int l = printSSHavingKsum(idx+1, v, sum, k);

    //Not pick
    sum -= v[idx];
    int r = printSSHavingKsum(idx+1, v, sum, k);

    return l+r;
}

int main()
{
    int n, k;
    cin>>n>>k;

    vector <int> v(n);
    for ( int i = 0; i < n; i++){
        cin>>v[i];
    }

    cout<<printSSHavingKsum(0, v, 0, k);
    
    return 0;
}
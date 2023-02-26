#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int sz = sqrt(n)+1;
    int arr[n], SQ[sz];
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }

    for (int i = 0; i < sz; i++){
        SQ[i] = INT_MAX;
    }

    for (int i = 0; i < n; i++){
        SQ[i/sz] = min(SQ[i/sz], arr[i]);
    }

    int q, l, r, mn = INT_MAX;
    cin>>q;
    while (q--){
        cin>>l>>r;
        l--, r--;

        for (int i = l; i <= r;){
            if ((i%sz == 0) && (i+sz-1 <= r)){
                mn = min(SQ[i/sz], mn);

                i += sz;
            }
            else {
                mn = min(arr[i], mn);
                i++;
            }
        } 

        cout<<mn<<"\n";   

        mn = INT_MAX;
    }

    return 0;
}

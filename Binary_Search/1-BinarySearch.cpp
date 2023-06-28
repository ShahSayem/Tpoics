#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll BinarySearch(ll target, vector <ll> &v){ //First Occurence
    int l = 0, r = v.size()-1;             // BinarySearch(target+1) == the idx after last occurence

    while (l < r){
        ll mid = l+(r-l)/2;

        if (v[mid] < target){
            l = mid +1;
        }
        else {
            r = mid;
        }
    }
    
    return l;
}

int main()
{
    ll n, target;
    vector <ll> v(n);
    for (int i = 0; i < n; i++){
        cin>>v[i];
    }
    
    ll idx;
    while (cin>>target){ 
        if (target == -1)
            break;

        idx = BinarySearch(target, v);  //Search for index of target
        cout<<target<<" idx: "<<idx<<"\n";
    }

    return 0;
} 
  

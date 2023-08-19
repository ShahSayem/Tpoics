#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll lowerBound(ll target, vector <ll> &v){ //First Occurence or next greater first occurence (if target is not present)
    int l = 0, r = v.size()-1, mid;      // lowerBound(target+1) = the idx after last occurence of target 
                                        // If the target is the last element than  lowerBound(target+1) = last idx 
    while (l < r){
        mid = l+(r-l)/2;

        if (v[mid] < target){
            l = mid +1;
        }
        else {
            r = mid;
        }
    }
    
    return l;
}

ll upperBound(ll target, vector <ll> &v){ //Last Occurence+1, it means next greater first occurence
    int l = 0, r = v.size()-1, mid;      // If the target is the last element than  upperBound(target) = last idx
                                         
    while (l < r){
        mid = l+(r-l)/2;

        if (v[mid] <= target){
            l = mid +1;
        }
        else {
            r = mid;
        }
    }
    
    return r;
}

int main()
{
    ll n;
    cin>>n;

    vector <ll> v(n);
    //Values:  5 5 5 12 14 23 23 23 23 33 36 42 49 55 55 55 61 65 69 70 78 81 87 88 91 97 98 98 98 98
    //indexes: 0 1 2 3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29
    for (int i = 0; i < n; i++){
        cin>>v[i];
    }
    
    ll lowerIdx, upperIdx, target;
    while (cin>>target){ 
        if (target == -1)
            break;

        lowerIdx = lowerBound(target, v);  //Search for index of target
        cout<<target<<" lower idx: "<<lowerIdx<<"\n";

        upperIdx = upperBound(target, v);  //Search for index of target
        cout<<target<<" upper idx: "<<upperIdx<<"\n";
    }

    return 0;
} 
  

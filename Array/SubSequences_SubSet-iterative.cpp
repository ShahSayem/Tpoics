#include <bits/stdc++.h>
using namespace std;

#define Shah_Sayem ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;
const ll MOD = 1e9+7;
const int MAX = 1e7+5;

//PowerSet -> Bit Manipulation
//O(n*2^n)
//{1, 2, 3} =>{}, {1}, {2}, {1, 2}, {3}, {2, 3}, {1, 3}, {1, 2, 3}

vector < vector <int> > powerSet(vector <int> &v)
{
    int n = v.size(), x = 1;
    x = x<<n;

    vector < vector <int> > allSubSeq;
    int curr;
    for (int i = 0; i < x; i++){
        curr = i;
        vector <int> currSubSeq;
        for (int j = 0; j < n; j++){
            if (curr & (1<<j)){
                currSubSeq.push_back(v[j]);
            }
        }
        //reverse currSubSeq if currSubSeq.push_back(v[n-j-1]);
        
        allSubSeq.push_back(currSubSeq);
    }
    
    return allSubSeq;
}

int main()
{
    vector <int> v = {1, 2, 3}; //1, 1, 2, 3, 3, 4, 7
    auto ans = powerSet(v);
    for (auto it : ans){
        for (auto it2 : it){
            cout<<it2<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}
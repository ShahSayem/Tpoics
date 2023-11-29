#include <bits/stdc++.h>
using namespace std;

#define Shah_Sayem ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;
const ll MOD = 1e9+7;
const int MAX = 1e7+5;

int main()
{
    int n;
    cin>>n;

    vector <int> v(n);
    for (int i = 0; i < n; i++){
        cin>>v[i];
    }
    
    //Algo
    ll sum = 0, mx = INT_MIN;
    int start = -1, ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++){
        if (sum == 0)
            start = i;

        sum += v[i];

        if (sum > mx){
            mx = sum;

            ansStart = start, ansEnd = i;
        }    

        if (sum < 0)
            sum = 0;
    }
    
    cout<<mx<<"\n";
    for (int i = ansStart; i <= ansEnd; i++){
        cout<<v[i]<<" ";
    }
    
    return 0;
}

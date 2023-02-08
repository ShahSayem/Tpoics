#include <bits/stdc++.h>
using namespace std;

int main()
{
    // int n;
    // cin>>n;
    // for (int i = 0; i <= n; i++){
    //     for (int j = 0; j <= n; j++){
    //         for (int k = 0; k <= n; k++){
    //             for (int l = 0; l <= n; l++){
    //                 for (int m = 0; m <= n; m++){
    //                     if ((i%7 == 0 || i%10 == 7) && (j%7 == 0 || j%10 == 7) && (k%7 == 0 || k%10 == 7) && (l%7 == 0 || l%10 == 7) && (m%7 == 0 || m%10 == 7)){
    //                         if (i+j+k+l+m == n){
    //                             cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<m<<"\n\n";
    //                         }
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }
    int n = 2, x;
    char ch;
    vector <pair <char, vector<int> > > px(n);
    for (auto it:px){
        cin>>ch;
        it.first = ch;
        for (int j = 0; j < n; j++){
            cin>>x;
            it.second.push_back(x);

            cout<<it.second[j]<<" ";
        }
        cout<<"\n";
    }

    for (auto it:px){
        for (auto it2:it.second){
            cout<<it2<<" ";
        }
    }
    
    return 0; 
}
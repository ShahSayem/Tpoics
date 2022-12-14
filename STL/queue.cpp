#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    queue <int> qu;

    qu.push(4);
    qu.push(5);
    qu.push(9);
    qu.push(2);

    cout<<"Queue elements: ";
    while (!qu.empty()){
        cout<<qu.front()<<" ";
        qu.pop();
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // int t;
    // cin>>t;
    // while (t--){
        solve();
        cout<<"\n";
    // }

    return 0;
}
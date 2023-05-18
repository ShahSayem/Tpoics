#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, pos;
    cout<<"Enter a decimal number and a position for checking on/off:";
    cin>>n>>pos;
    
    if((n & (1<<pos)) != 0){
        cout<<1<<endl;
    }
    else{
        cout<<0<<endl;
    }
    
    return 0;
}
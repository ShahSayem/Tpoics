#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, pos;
    cout<<"Enter a decimal number and a position for clear bit:";
    cin>>n>>pos;
    
    int mask = ~(1<<pos);
    cout<<(n & mask)<<endl;
 
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, pos, value;
    cout<<"Enter a decimal number, a position and a value for update bit:";
    cin>>n>>pos>>value;
    
    int mask = ~(1<<pos);
    n = n & mask;
    cout<<(n | (value<<pos))<<endl;
 
    return 0;
}
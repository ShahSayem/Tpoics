#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, pos;
    cout<<"Enter a decimal number and a position for set bit:";
    cin>>n>>pos;
    
    cout<<(n | (1<<pos))<<endl;
 
    return 0;
}
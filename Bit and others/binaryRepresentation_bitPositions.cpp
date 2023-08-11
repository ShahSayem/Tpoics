#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long double pi = 3.14159265358979323846;
const ll MOD = 1e9+7;
const int MAX = 10000000;

void binaryRepresentation(int n) //is the bit on or not / Binary representation
{
    for (int i = 30; i >= 0; i--){
        if (n & (1LL<<i) != 0)
            cout<<1<<" ";
        else
            cout<<0<<" ";
    } 
} 

void bitPositions(int n) //will show the bit positions
{
    for (int i = 0; i <= 30; i++){
        if (n & (1LL<<i) != 0)
            cout<<i<<" ";
    }
} 

int main()
{    
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;

        binaryRepresentation(n);
        cout<<"\n";
        bitPositions(n);
        cout<<"\n";
    }

    return 0;
} 
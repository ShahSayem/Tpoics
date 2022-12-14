#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void print1toN(int n)
{
    if (n == 0)
        return;
    
    print1toN(n-1);
    cout<<n<<"\n";
}

void printNto1(int n)
{
    if (n == 0)
        return;
    
    cout<<n<<"\n";
    printNto1(n-1);
}

int main()
{   
    int n;
    cin>>n;
    cout<<"1 to n:\n";
    print1toN(n);

    cout<<"\nn to 1:\n";
    printNto1(n);

    return 0;
} 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void printName(string s, int n)
{
    if (n == 0)
        return;
    
    cout<<s<<" "<<n<<"\n";

    printName(s, n-1);
}

int main()
{   
    int n;
    cin>>n;

    string s = "Sayem";

    printName(s, n);

    return 0;
} 
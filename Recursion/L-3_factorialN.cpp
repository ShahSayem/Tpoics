#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int fact(int n) 
{
    if (n == 1){
        return 1;
    }

    return n*fact(n-1);
}

int main()
{   
    int n;
    cin>>n;

    cout<<"Factorial of "<<n<<": ";
    int x = fact(n);
    cout<<x;

    return 0;
} 
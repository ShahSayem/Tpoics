#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int sumTillN(int n, int sum) //Perameter concept
{
    if (n == 0){
        cout<<sum<<"\n";
        return 0;
    }

    sumTillN(n-1, sum+n);
}

int sumTillNF(int n) //Functional concept
{
    if (n == 0){
        return 0;
    }

    return n+sumTillNF(n-1);
}

int main()
{   
    int n;
    cin>>n;

    cout<<"sumTillN Perameter concept: ";
    sumTillN(n, 0);

    cout<<"sumTillNF Functional concept: ";
    int x = sumTillNF(n);
    cout<<x;
    
    return 0;
} 
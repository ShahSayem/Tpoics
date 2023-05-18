#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int cnt = 0;

int print()
{
    if (cnt == 3)
        return 0;
    
    cout<<cnt<<"\n";
    cnt++;

    print();
}

int main()
{   
    print();

    return 0;
} 
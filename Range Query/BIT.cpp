#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 100000+5;

int arr[MAX];   //Good to use 1 base inedxing
ll bit1[MAX];
ll bit2[MAX];
int n;

ll query(int idx, ll *bit)
{
    ll sum = 0;
    while (idx > 0){
        sum += bit[idx];
        idx -= (idx & -idx);
    }
    
    return sum;
}

void update(int idx, ll val, ll *bit)
{
    while (idx <= n){
        bit[idx] += val;
        idx += (idx & -idx);
    }
}

void rangeUpdate(int l, int r, int val)
{
    update(l, val, bit1);
    update(r+1, -val, bit1);

    update(l, val*(l-1), bit2);
    update(r+1, -val*r, bit2);
}

ll rangeQuery(int l, int r)
{   
    ll sum1 = query(r, bit1)*r - query(r, bit2);
    ll sum2 = query(l-1, bit1)*(l-1) - query(l-1, bit2);

    return sum1 - sum2;
}


int main()
{
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++){
        cin>>arr[i];

        rangeUpdate(i, i, arr[i]);
    }
    

    return 0;
}

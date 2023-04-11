#include <bits/stdc++.h>
using namespace std;

int query(int idx)
{
    int sum = 0;

    while (idx > 0){
        sum += tree[idx];
        idx -= idx & (-idx);
    }

    return sum;
}

void update(int idx, int val, int len)
{
    while (idx <= len){
        tree[idx] += val;
        idx += idx & (-idx);
    }
}

int main()
{
    

    return 0;
}

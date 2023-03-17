#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
const int MAX = 100000;
int arr[MAX];
struct Tree
{
    ll sum, prop;
} tree[4*MAX+1];

void init(int node, int b, int e)
{
    if (b == e){
        tree[node].sum = arr[b];
        return;
    }

    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);
    tree[node].sum = tree[left].sum + tree[right].sum;
}

ll query(int node, int b, int e, int i, int j, ll carry = 0)
{
    if (i > e || j < b){
        return 0;
    }

    if (b >= i && e <= j){
        return tree[node].sum + ((e - b + 1) * carry);
    }

    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b + e) / 2;

    ll leftSum = query(left, b, mid, i, j, carry + tree[node].prop);
    ll rightSum = query(right, mid + 1, e, i, j, carry + tree[node].prop);
    
    return leftSum + rightSum;
}

void update(int node, int b, int e, int i, int j, ll val)
{
    if (i > e || j < b)
        return;

    if (b >= i && e <= j){
        tree[node].sum += (e - b + 1) * val;
        tree[node].prop += val;

        return;
    }

    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b + e) / 2;

    update(left, b, mid, i, j, val);
    update(right, mid + 1, e, i, j, val);
    tree[node].sum = tree[left].sum + tree[right].sum + (e - b + 1)*tree[node].prop;
}

int main()
{
    int n;  //8
    cin>>n;
    for (int i = 0; i < n; i++){    //8, 4, 3, 5, 2, 3, 10, 7
        cin>>arr[i];
    }
    init(0, 0, n-1);

    int q, type, l, r, val;
    cin>>q;
    while (q--){
        cin>>type;

        if (type == 1){
            cin>>l>>r;
            cout<<query(0, 0, n-1, l, r)<<"\n";
        }
        else {
            cin>>l>>r>>val;
            update(0, 0, n-1, l, r, val);
        }
    }
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

const int MAX = 10000000+5;

int arr[MAX];
int tree[4*MAX+1];

void init(int node, int b, int e)   //b-e: range
{
    if(b == e){
        tree[node] = arr[b];

        return;
    }

    int left = node*2 + 1;
    int right = node*2 + 2;
    int mid = (b+e)/2;

    init(left, b, mid);
    init(right, mid+1, e);
    tree[node] = tree[left] + tree[right];
}

int query(int node, int b, int e, int i, int j)
{
    if (b > j || e < i){
        return 0;
    }

    if (b >= i && e <= j){
        return tree[node];
    }

    int left = node*2 + 1;
    int right = node*2 + 2;
    int mid = (b+e)/2;

    int leftSum = query(left, b, mid, i, j);
    int rightSum = query(right, mid+1, e, i, j);
    return leftSum + rightSum;
}

void update (int node, int b, int e, int target, int val)
{   if (b > target || e < target)
        return;

    if (b == target && e == target){
        tree[node] = val; //node != target (target -> array idx)
                         //node -> tree idx
        return;
    }

    int left = node*2 + 1;
    int right = node*2 + 2;
    int mid = (b+e)/2;

    update(left, b, mid, target, val);
    update(right, mid+1, e, target, val);
    tree[node] = tree[left] + tree[right];
}

int main()
{
    int n;  //7
    cin>>n;
    for (int i = 0; i < n; i++){    //5, 1, 2, 6, 3, 5, 9
        cin>>arr[i];
    }
    
    init(0, 0, n-1);
    cout<<query(0, 0, 6, 2, 5)<<"\n";
    cout<<tree[0]<<"\n";

    update(0, 0, 6, 1, 5);
    cout<<tree[0]<<"\n";

    return 0;
}

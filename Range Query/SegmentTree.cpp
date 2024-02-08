#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 100000+5;

int arr[MAX];
//mode: 1.Min, 2.Max, 3.Sum 
class SegTree {
public:    
    vector <ll> tree;
    SegTree(int n){
        tree.resize(4*n+1);
    }
    
    void init(int node, int b, int e, int mode)   //b-e: range
    {
        if(b == e){
            tree[node] = arr[b];

            return;
        }

        int left = node*2 + 1;
        int right = node*2 + 2;
        int mid = (b+e)/2;

        init(left, b, mid, mode);
        init(right, mid+1, e, mode);

        if (mode == 1)
            tree[node] = min(tree[left], tree[right]);
        else if (mode == 2)
            tree[node] = max(tree[left], tree[right]);
        else //3
            tree[node] = tree[left] + tree[right];
    }

    ll query(int node, int b, int e, int i, int j, int mode)
    {
        if (b > j || e < i){
            if (mode == 1)
                return LLONG_MAX;
            else if (mode == 2)
                return LLONG_MIN;
            else //3
                return 0;
        }

        if (b >= i && e <= j){
            return tree[node];
        }

        int left = node*2 + 1;
        int right = node*2 + 2;
        int mid = (b+e)/2;

        ll leftQ = query(left, b, mid, i, j, mode);
        ll rightQ = query(right, mid+1, e, i, j, mode);

        if (mode == 1)
            return min(leftQ, rightQ);
        else if (mode == 2)
            return max(leftQ, rightQ);
        else //3
            return (leftQ + rightQ);
    }

    void update (int node, int b, int e, int target, int val, int mode)
    {   
        if (b > target || e < target)
            return;

        if (b == target && e == target){
            tree[node] = val; //node != target (target -> array idx)
                            //node -> tree idx
            return;
        }

        int left = node*2 + 1;
        int right = node*2 + 2;
        int mid = (b+e)/2;

        update(left, b, mid, target, val, mode);
        update(right, mid+1, e, target, val, mode);

        if (mode == 1)
            tree[node] = min(tree[left], tree[right]);
        else if (mode == 2)
            tree[node] = max(tree[left], tree[right]);
        else //3
            tree[node] = tree[left] + tree[right];
    }
};

int main()
{
    int n;  //7
    cin>>n;
    for (int i = 0; i < n; i++){    //5 1 2 6 3 5 9
        cin>>arr[i];
    }
    
    SegTree sg(n);
    sg.init(0, 0, n-1, 3); //sum
    cout<<sg.query(0, 0, n-1, 2, 5, 3)<<"\n";
    cout<<sg.tree[0]<<"\n";

    sg.update(0, 0, n-1, 1, 5, 3);
    cout<<sg.tree[0]<<"\n";

    return 0;
}

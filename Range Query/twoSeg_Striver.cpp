#include<bits/stdc++.h>
using namespace std;

const int MAX = 10000000+5;

class SGTree {
public:
    vector <int> tree;
    SGTree(int n){
        tree.resize(4*n+1);
    }

    void init(int node, int b, int e, int arr[])   //b-e: range
    {
        if(b == e){
            tree[node] = arr[b];

            return;
        }

        int left = node*2 + 1;
        int right = node*2 + 2;
        int mid = (b+e)/2;

        init(left, b, mid, arr);
        init(right, mid+1, e, arr);
        tree[node] = min(tree[left], tree[right]);
    }

    int query(int node, int b, int e, int i, int j)
    {
        if (b > j || e < i){
            return INT_MAX;
        }

        if (b >= i && e <= j){
            return tree[node];
        }

        int left = node*2 + 1;
        int right = node*2 + 2;
        int mid = (b+e)/2;

        int leftMN = query(left, b, mid, i, j);
        int rightMN = query(right, mid+1, e, i, j);
        return min(leftMN, rightMN);
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
        tree[node] = min(tree[left], tree[right]);
    } 
};


void solve()
{
    int n1, n2;  //7
    cin>>n1;
    int arr1[n1];
    for (int i = 0; i < n1; i++){   
        cin>>arr1[i];
    } 
    SGTree sg1(n1);
    sg1.init(0, 0, n1-1, arr1);

    cin>>n2;
    int arr2[n2];
    for (int i = 0; i < n2; i++){    //5, 1, 2, 6, 3, 5, 9
        cin>>arr2[i];
    } 
    SGTree sg2(n2);
    sg2.init(0, 0, n2-1, arr2);

    int q, type, l1, r1, l2, r2, mn1, mn2, arrNo, idx, val;
    cin>>q;

    while (q--){
        cin>>type;

        if (type == 1){
            cin>>l1>>r1>>l2>>r2;
            mn1 = sg1.query(0, 0, n1-1, l1, r1);
            mn2 = sg2.query(0, 0, n2-1, l2, r2);

            cout<<min(mn1, mn2)<<"\n";
        }
        else {
            cin>>arrNo>>idx>>val;
            
            if (arrNo == 1){
                sg1.update(0, 0, n1-1, idx, val);
                arr1[idx] = val;
            }
            else {
                sg2.update(0, 0, n2-1, idx, val);
                arr2[idx] = val;
            }
        }
    }
}

int main ()
{
    int t = 1;
    //cin>>t;

    while (t--)
        solve();  

    return 0;
}


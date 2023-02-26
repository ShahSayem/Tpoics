#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000000+5;
int sqroot;

struct query{
    int left, right, idx;
};
query Q[MAX];

bool cmp (query Q1, query Q2)
{
    if (Q1.left/sqroot == Q2.left/sqroot){
        return Q1.right > Q2.right;
    }

    return Q1.left/sqroot < Q2.left/sqroot;
}

int main()
{
    int n;
    cin>>n;

    sqroot = sqrt(n)+1;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int  q, l, r;
    cin>>q;

    for (int i = 0; i < q; i++){
        cin>>l>>r;

        Q[i].left = l;
        Q[i].right = r;
        Q[i].idx = i;
    }

    sort(Q, Q+q, cmp);
    int ans[q];
    int b = 0, e = -1, currAns = 0;

    for (int i = 0; i < q; i++){
        l = Q[i].left;
        r = Q[i].right;
        l--, r--;

        while (e < r){  
            e++;
            currAns += arr[e];
        }

        while (e > r){ 
            currAns -= arr[e];
            e--;
        }

        while (b > l){  
            b--;
            currAns += arr[b];
        }

        while (b < l){
            currAns -= arr[b];
            b++;
        }

        ans[Q[i].idx] = currAns;   
    }

    for (int i = 0; i < q; i++){
        cout<<ans[i]<<"\n";
    }
       
    return 0;
}

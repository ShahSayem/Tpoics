#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// order_of_key(k): Number of items strictly smaller than k
// find_by_order(k): k-th element in a set(0 based)


int main()
{
    oset <int> s;
    int q, operation, val, k;
    cin>>q;
    while (q--){
        cin>>operation;

        if (operation == 1){
            cin>>val;
            s.insert(val);
        }
        else if (operation == 2){ //k-th element
            cin>>k;
            cout<<*s.find_by_order(k)<<"\n";
        }
        else{  //Number of items strictly smaller
            cin>>k;
            cout<<s.order_of_key(k)<<"\n";
        }
    }
    
    return 0;
}

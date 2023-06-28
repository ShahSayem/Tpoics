#include <bits/stdc++.h>
using namespace std;

bool printSSHavingKsum(int idx, vector <int> &v, vector <int> &sequences, int sum, int k)
{
    if (idx == v.size()){   //condition satisfied
        if (sum == k){
            for (auto it : sequences)
                cout<<it<<" ";

            cout<<"\n";
            return true;
        }
        return false;   //condition not satisfied
    }

    //Pick
    sequences.push_back(v[idx]);
    sum += v[idx];
    if (printSSHavingKsum(idx+1, v, sequences, sum, k))
        return true;

    //Not pick
    sequences.pop_back();
    sum -= v[idx];
    if (printSSHavingKsum(idx+1, v, sequences, sum, k))
        return true;

    return false;
}

int main()
{
    int n, k;
    cin>>n>>k;

    vector <int> v(n), sequences;
    for ( int i = 0; i < n; i++){
        cin>>v[i];
    }

    printSSHavingKsum(0, v, sequences, 0, k);
    
    return 0;
}
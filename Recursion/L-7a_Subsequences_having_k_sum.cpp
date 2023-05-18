#include <bits/stdc++.h>
using namespace std;

void printSSHavingKsum(int idx, vector <int> &v, vector <int> &sequences, int sum, int k)
{
    if (idx == v.size()){
        if (sum == k){
            for (auto it : sequences)
                cout<<it<<" ";

            cout<<"\n";
        }
        return;
    }

    //Pick
    sequences.push_back(v[idx]);
    sum += v[idx];
    printSSHavingKsum(idx+1, v, sequences, sum, k);

    //Not pick
    sequences.pop_back();
    sum -= v[idx];
    printSSHavingKsum(idx+1, v, sequences, sum, k);
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
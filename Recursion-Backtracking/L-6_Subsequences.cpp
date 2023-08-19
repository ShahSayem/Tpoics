#include <bits/stdc++.h>
using namespace std;

void PrintSubseq(int idx, vector <int> &subseq, vector <int> &v, int n)
{
    if (idx == n){
        for (auto it : subseq){
            cout<<it<<" ";
        }

        if (subseq.size() == 0){
            cout<<"{}"; 
        }
        cout<<"\n";
        return;
    }

    //take the index
    subseq.push_back(v[idx]);
    PrintSubseq(idx+1, subseq, v, n);

    //not take the index
    subseq.pop_back();
    PrintSubseq(idx+1, subseq, v, n);
}

int main()
{
    int n;
    cin>>n;

    vector <int> v(n), subseq;
    for (int i = 0; i < n; i++){
        cin>>v[i];
    }

    PrintSubseq(0, subseq, v, n);
    
    return 0;
}
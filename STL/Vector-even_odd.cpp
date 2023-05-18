#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector <int> even;
    vector <int> odd;

    for (int i = 0; i < n; i++){
        int j;
        cin>>j;

        if (j%2 == 0)
            even.push_back(j);
        else
            odd.push_back(j);
    }
    
    for (int i = 0; i < even.size(); i++){
        cout<<even[i]<<" ";
    }
    cout<<endl;

    for (int i = 0; i < odd.size(); i++){
        cout<<odd[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
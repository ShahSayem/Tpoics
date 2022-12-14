#include <bits/stdc++.h>
using namespace std;

int main()
{
    //Result problem
    int n;
    cin>>n;

    vector <pair<int, string>> v; //score, name
    vector <pair<int, string>> it;

    for (int i = 0; i < n; i++){
        int j;
        cin>>j;

        string s;
        cin>>s;

        v.push_back(make_pair(j, s));
    }
    cout<<endl;
    sort(v.begin(), v.end(), greater<pair<int, string>>());


    for (int i = 0; i < v.size(); i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    
    return 0;
}
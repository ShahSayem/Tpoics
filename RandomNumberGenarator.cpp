#include <bits/stdc++.h>
#define   ll   long long
using namespace std;

vector <int> generateDistinctVal(int cnt, int mn, int mx) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(mn, mx);

    vector<int> values;
    for (int i = mn; i <= mx; ++i) {
        values.push_back(i);
    }

    shuffle(values.begin(), values.end(), gen);

    return vector<int>(values.begin(), values.begin() + cnt);
}

int main()
{
    int cnt;
    cin>>cnt;

    int mn = 1;
    int mx = 100000000;

    freopen("Input-2(100).txt", "w", stdout);
    vector<int> randomValues = generateDistinctVal(cnt, mn, mx);
    for (int value : randomValues) {
        cout<<value<<"\n";
    }
    
    return 0;
}
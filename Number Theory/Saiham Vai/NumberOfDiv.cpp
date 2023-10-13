//Shah Sayem
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long double pi = 3.14159265358979323846;
const ll MOD = 1e9+7;
const int MAX = 10000000;

///.........Graph.........///
//vector <int> adj[10000000];
int X[] = {1, -1, 0, 0};
int Y[] = {0, 0, 1, -1};

int GCD(int a, int b)
{
    if (!b)
        return a;
    
    return GCD(b, a%b);
}

void numOfDiv(int n)
{
    vector <int> div;
    for (int i = 1; i*i <= n ; i++){
        if (n%i == 0){
            div.push_back(i);
            if (i*i != n){
                div.push_back(n/i);
            }
        }
    }
    
    for (int i = 0; i < div.size(); i++){
        cout<<div[i]<<" ";
    }
}

int main()
{

    int n;
    cin>>n;
    
    numOfDiv(n);

    //cout<<GCD(16, 12);
    return 0;
}

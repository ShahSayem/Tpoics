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

vector <bool> composite(MAX);
void sieveOfEratosthenes()
{
    composite[0] = true, composite[1] = true;
    for (int i = 2; i*i <= MAX; i++){
        if (!composite[i]){
            for (int j = i*i; j <= MAX; j+=i){
                composite[j] = true;
            } 
        }
    }    
} 

void primeFact(int n)
{
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    primeFact(n);

    return 0;
}

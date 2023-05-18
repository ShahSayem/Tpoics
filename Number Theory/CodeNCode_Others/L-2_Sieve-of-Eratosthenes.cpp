#include <bits/stdc++.h>
#define   ll   long long
using namespace std;

const int MAX = 1000000;

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

int main()
{
    sieveOfEratosthenes();
    cout<<endl;     
    
    return 0;
}
    
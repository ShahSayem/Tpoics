#include<bits/stdc++.h>
#define mx 100005
#define lld long long int
using namespace std;
lld arr[mx];
//lld tree[mx*3];

int main()
{

    int x = 27, cnt = 0;
    bool check = 0;
    for (int i = 0; i < 10; i++){
        check = 0;
        cnt = 0;
        while (cnt < 10){
            cnt++;

            if (cnt > 5){
                cout<<i<<" "<<cnt<<" ";
                cnt = 0;
                check = 1;
                break;
            }

            if (check){
                cout<<"Check"<<"\n";
            }
            else {
                cout<<"Not"<<"\n";
            }
        }      
    }
    
    
    //cout<<"\n\n"<<cnt;
    return 0;
}
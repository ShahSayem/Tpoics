#include <bits/stdc++.h>
using namespace std;

#define Shah_Sayem ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;
const ll MOD = 1e9+7;
const int MAX = 1e7+5;
ll x;
        //set using Bitmusking 
class mySet  //(0 <= num <= 60)
{
public:

    mySet(){
        x = 0;
    }

    void add(ll num){
        x = (x | (1LL<<num));
    }

    void remove (ll num){ 
        x = (x & (~(1LL<<num)));
    }

    void print(){ 
        for (ll i = 0; i < 64; i++){
            if ((1LL<<i) & x)
                cout<<i<<" ";
        }
        cout<<"\n";
    }
};

int main()
{
    mySet st;

    st.add(0);
    st.add(1);
    st.add(3);
    st.add(6);
    st.add(1);

    st.print();

    //cout<<x<<"\n";

    st.remove(1);
    st.remove(1);
    st.remove(3);

    st.add(9);

    st.print();

    return 0;
}

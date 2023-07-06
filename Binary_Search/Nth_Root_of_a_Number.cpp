#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// From LUV

ll int_sqrtRoot(ll n){  //return int of sqrt(n)
    // 1 2 3 4 5 6 7 8 9
    int l = 1, r = n, mid;      
                                       
    while (l < r){
        mid = l+(r-l)/2;

        if (mid*mid < n){
            l = mid +1;

            // cout<<l<<" ";
        }
        else {
            r = mid;
        }
    }
    
    return l;
}

double eps = 1e-7; //for 7 digit accurate precision

double multiply(double mid, int n){
    double ans = 1;
    for (int i = 0; i < n; i++){
        ans *= mid;
    }
    
    return ans;
}

double NthRoot(double x, int n){  //return Nth root(x)
    double l = 1, r = x, mid;    // O(nLog(x*(10^d))) //for finding Nth root
                                       
    while (r-l > eps){
        mid = l+(r-l)/2;

        if (multiply(mid, n) < x){ //use (mid*mid < x) for sqrt(double)
            l = mid;

            // cout<<l<<" ";
        }
        else {
            r = mid;
        }
    }
    
    return l; //Here, l = r
}

int main()
{
    int n;
    double x, root;
    while (cin>>x>>n){ 
        if (x == -1 && n == -1)
            break;

        root = NthRoot(x, n);
        if (sqrt(x)*sqrt(x) == x && n == 2)  //for removing precision loss of complete square numbers(1, 4, 9, 16, 25...)
            root = round(root);

        cout<<setprecision(10)<<root<<"\n";
    }

    return 0;
} 
  

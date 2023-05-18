#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{
    queue <int> qu;

    qu.push(4);
    qu.push(5);
    qu.push(9);
    qu.push(2);

    cout<<"Queue elements: ";
    while (!qu.empty()){
        cout<<qu.front()<<" ";
        qu.pop();
    } 

    return 0;
}
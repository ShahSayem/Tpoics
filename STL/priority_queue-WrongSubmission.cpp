#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define pi = 3.14159265358979323846
#define MOD = 1e9+7

void printQueue(priority_queue <int> pq)
{
    while (!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<"\n";
}

int cmp (int left, int right)
{
    return left < right;
}

int main()
{
    priority_queue <int> pq, pq2;
    for (int i = 0; i < 11; i++){
        pq.push(i);
        pq2.push(i*5);
    }
    
    printQueue(pq);

    cout<<pq.top()<<"\n";
    pq.pop();
    cout<<pq.top()<<"\n";

    printQueue(pq2);

    pq.swap(pq2);
    printQueue(pq2);

    pq2.emplace(333);
    printQueue(pq2);

    return 0;
} 
  

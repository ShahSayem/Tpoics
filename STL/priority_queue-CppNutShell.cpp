#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define pi = 3.14159265358979323846
#define MOD = 1e9+7

void printQueue(auto &pq)
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
    priority_queue <int> pq;
    for (int elem: {1, 8, 5, 6, 3, 4, 0, 9, 7, 2}){
        pq.push(elem);
    }
    
    printQueue(pq);

    priority_queue <int, vector <int>, greater <int> > pq2;
    for (int elem: {1, 8, 5, 6, 3, 4, 0, 9, 7, 2}){
        pq2.push(elem);
    }
    
    printQueue(pq2);

    priority_queue <int, vector <int>, less <int> > pq3 ;
    for (int elem: {1, 8, 5, 6, 3, 4, 0, 9, 7, 2}){
        pq3.push(elem);
    }
    
    printQueue(pq3);

    return 0;
} 
  

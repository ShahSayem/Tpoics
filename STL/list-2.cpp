#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    int a[5] = {1, 2, 3, 4, 5};

    list <int> mylist (a, a+5); // copy array to list
    list <int>::iterator it;

    for (it = mylist.begin(); it != mylist.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    
    it = mylist.begin();
    it++;
    mylist.insert(it, 10); // insert an element before iterator

    for (it = mylist.begin(); it != mylist.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    it = find(mylist.begin(), mylist.end(), 4); // it pointing to 4
    mylist.insert(it, 20);

    for (it = mylist.begin(); it != mylist.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    it = find(mylist.begin(), mylist.end(), 786); // it pointing to mylist.end(n+1)

    if(it == mylist.end())
        cout<<"Not found (-_-)"<<endl;
    else 
        cout<<"Found!!!"<<endl;

    it = mylist.begin();
    mylist.erase(it); // erase iterator pointed element
    for (it = mylist.begin(); it != mylist.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    return 0;
}

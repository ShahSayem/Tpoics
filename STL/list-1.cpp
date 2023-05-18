#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main()
{
    list <float> mylist;
    list <float>::iterator it;

    mylist.push_back(10);
    mylist.push_back(15);
    mylist.push_front(5);
    
    for (it = mylist.begin(); it != mylist.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    mylist.reverse();
    for (it = mylist.begin(); it != mylist.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    cout<<"size of list "<<mylist.size()<<endl;

    mylist.clear();
    cout<<"size of list "<<mylist.size()<<endl;

    list <float> mylist2 (4, -1);
    for (it = mylist2.begin(); it != mylist2.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    return 0;
}
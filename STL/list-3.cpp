#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    int a[5] = {1, 2, 3, 4, 5};

    list <int> mylist (a, a+5);

    if (mylist.empty())
        cout<<"Empty"<<endl;
    else
        cout<<"Filled"<<endl;

    cout<<mylist.front()<<" "<<mylist.back()<<endl;

    list <int>::iterator it;
    for (it = mylist.begin(); it != mylist.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    mylist.pop_front();
    mylist.pop_back();
    for (it = mylist.begin(); it != mylist.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;



    return 0;
}

//Extra functions comparing vector: insert(), push_front(), pop_front()
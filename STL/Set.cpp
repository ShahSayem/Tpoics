#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    set <int> s;
    set <int>::iterator it;

    s.insert(10);
    s.insert(3);
    s.insert(5);
    s.insert(10);

    for (it = s.begin(); it != s.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    it = s.find(5);
    s.erase(it);
    for (it = s.begin(); it != s.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    s.insert(5);

    s.erase(s.find(3));
    for (it = s.begin(); it != s.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    set <string> s2;
    set <string>::iterator it2;

    cout<<"Enter 4 names: ";
    for (int i = 0; i < 4; i++){
        string name;
        cin>>name;
        s2.insert(name);
    }

    cout<<"Output: ";
    for (it2 = s2.begin(); it2 != s2.end(); it2++){
        cout<<*it2<<" ";
    }
    cout<<endl;
    
    pair <set <string>::iterator, bool> p;
    p = s2.insert("Sayem");

    if (p.second)
        cout<<"Inserted"<<endl;
    else
        cout<<"Can't insert"<<endl;
        
    return 0;
}
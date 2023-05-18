#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    pair <string, int> p;
    p.first = "Hasan";
    p.second = 21;
    cout<<p.first<<" "<<p.second<<endl;

    pair <string, int> p2("Sayem", 22);
    cout<<p2.first<<" "<<p2.second<<endl;

    p2 = make_pair("Ohi", 20);
    cout<<p2.first<<" "<<p2.second<<endl;

    return 0;
}
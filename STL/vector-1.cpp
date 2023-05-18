#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    // 1 2 3

    cout<<vec[1]<<endl;

    vec[1] = 0;
    // 1 0 3

    cout<<vec[1]<<endl;

    vector <int>::iterator it;
    it = vec.begin(); // as like pointer
    cout<<*it<<endl;

    it++;
    cout<<*it<<endl;

    for( it = vec.begin(); it != vec.end(); it++){
        cout<<*it<<endl;
    }

    return 0;
}
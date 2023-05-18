#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    map <string, int> m;
    map <string, int>::iterator it;

    m["Dipta"] = 43; //inserting values
    m["Arnob"] = 42;
    m["Arnob"] = 45; //changing values
    m.insert(make_pair("Nabil", 41)); 

    cout<<m["Arnob"]<<endl;

    it = m.begin();
    cout<<it->first<<endl;

    for (it = m.begin(); it != m.end(); it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    
    

    return 0;
}

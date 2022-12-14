#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    vector < pair<int, string> > vec;
    vector < pair<int, string> >::iterator it;

    vec.push_back(make_pair(21, "Hasan"));
    vec.push_back(make_pair(22, "Sayem"));
    vec.push_back(make_pair(20, "Dilwar"));

    cout<<vec[0].first<<" "<<vec[0].second<<endl<<endl;

    for (it = vec.begin(); it != vec.end(); it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<endl;

    for (int i = 0; i<vec.size(); i++){
        cout<<vec[i].first<<" "<<vec[i].second<<endl;
    }
    
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector <int> vec;

    for(int i = 0; i < 5; i++){
        int j;
        cin>>j;

        vec.push_back(j);
    }

    sort(vec.begin(), vec.end());

    for(int i = 0; i < 5; i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    
    reverse(vec.begin(), vec.end());


    for(int i = 0; i < 5; i++){

    cout<<vec[i]<<" ";
    }

    vec.clear();
    cout<<"size of vector "<<vec.size()<<endl;

    return 0;
}

//Other functionalities: find(), erase(), empty()
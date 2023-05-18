#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    int arr[5] = {1, 4, 5, 8, 9};

    bool ans = binary_search(arr, arr+5, -10);

    if (ans)
        cout<<"-10 is found!!!"<<endl;
    else
        cout<<"-10 not found (-_-)"<<endl;

    int pos4 = lower_bound(arr, arr+5, 4)-arr; //1 (index)
    int pos7 = lower_bound(arr, arr+5, 7)-arr; //3 (index of immediate next greater element)
    int pos10 = lower_bound(arr, arr+5, 10)-arr; //5 (index of immediate next greater element--there is no greater element)

    cout<<"Positions_lower: "<<pos4<<" "<<pos7<<" "<<pos10<<endl;

    vector <int> v = {6, 4, 2, 69, 11};
    int pos = lower_bound(v.begin(), v.end(), 71)-v.begin(); //same as array 

    // can be use for found first occurance


    int pos4b = upper_bound(arr, arr+5, 4)-arr; //2 (always return index of immediate next greater element)
    int pos7b = upper_bound(arr, arr+5, 7)-arr; //3 (always return index of immediate next greater element)
    int pos10b = upper_bound(arr, arr+5, 10)-arr; //5 (always return index of immediate next greater element)

    cout<<"Positions-upper: "<<pos4b<<" "<<pos7b<<" "<<pos10b<<endl;

    int posb = upper_bound(v.begin(), v.end(), 71)-v.begin(); //same as array 
      
    // can be use for found last occurance
    
    return 0;
}
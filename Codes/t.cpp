#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> arr;
    for(int i=0; i<11; i++)
    {
        arr.push_back(i);
        cout<<arr[i]<<" "<<arr.size()<<" "<<arr.capacity()<<endl;
    }

    cout<<arr[0];
    
    
}
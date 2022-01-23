// A STL based C++ program to sort a nearly sorted array.
#include <bits/stdc++.h>
using namespace std;
 
// Given an array of size n, where every element
// is k away from its target position, sorts the
// array in O(n logk) time.
void sortK(int arr[], int n, int k)
{
     
    priority_queue<int, vector<int>, greater<int> > pq;

    for(int i=0; i<k; i++){
        pq.push(arr[i]);
    }

    int j=0;

    int index = 0;
    for (int i = k; i < n; i++) {
        arr[j++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }
 
    while (!pq.empty()) {
        arr[j++] = pq.top();
        pq.pop();
    }
}
 
// A utility function to print array elements
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
// Driver program to test above functions
int main()
{
    int k = 3;
    int arr[] = { 2, 6, 3, 12, 56, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    sortK(arr, n, k);
 
    cout << "Following is sorted array" << endl;
    printArray(arr, n);
 
    return 0;
}
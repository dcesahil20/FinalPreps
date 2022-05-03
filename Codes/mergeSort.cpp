#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &left, vector<int> &right, vector<int> &res){
    
    int leftS = 0;
    int leftE = left.size()-1;

    int rightS = 0;
    int rightE = right.size()-1;

    int fSize = left.size() + right.size();
    int k = 0;

    while(k<fSize && (leftS < leftE && rightS < rightE)){
        if(left[leftS] < right[rightS]){
            res[k++] = left[leftS++];
        }
        else if (left[leftS] > right[rightS]){
            res[k++] = right[rightS++];
        }
    }

    while(leftS < leftE && k<fSize){
        res[k++] = left[leftS++];
    }

    while(rightS < rightE && k<fSize){
        res[k++] = left[rightE++];
    }
    
}

vector<int> mergeSort(vector<int> &arr, int lo, int hi){
      
    int mid;
    vector<int> res;

    if(lo<hi){
        vector<int> left = mergeSort(arr, lo, mid-1);
        vector<int> right = mergeSort(arr, mid, hi);
        merge(left, right, res);
    }    
    return res;
}


int main(){
    vector<int> arr = {4,3,5,6,1,5,6,8,9,0,8,6,5,34,2,2,43};
    cout  << arr[1] ;
    int lo = 0;
    int hi = arr.size()-1;
    vector<int> msar = mergeSort(arr, lo, hi);

    for(auto i : msar){
        cout << i << " ";
    }
    cout << endl;
}
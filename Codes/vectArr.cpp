#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> varr[5];

    for(int i=0; i<5; i++){
        varr[i].push_back(i+1);
        varr[i].push_back(i+2);
        varr[i].push_back(i+3);
    }
    
    for(int i =0; i<5; i++){
        for(int j=0; j<varr[i].size(); j++){
            cout << varr[i][j] << endl;
        }
    }
}
#include <iostream>
#include <vector>
using namespace std;

int fib(int n, vector<int> &dp){

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[n];
}

int main(){
    int n;
    cin >> n;

    int prev = 1;
    int prev2 = 0;

    for(int i=2; i<=n; i++){
        int cur = prev + prev2;
        prev2 = prev;
        prev = cur;
    }

    cout <<  prev;

}
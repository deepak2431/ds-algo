//Find the minimum cost of operations to multiply given n matrices
#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int dp[20][20];

void init() {
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            dp[i][j] = -1;
        }
    }
}


int solve(int arr[], int i, int j) {

    if(i >= j) {
        return 0;
    }
    int ans = INT_MAX;
    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    for(int k = i; k < j; k++) {
        int count = solve(arr, i, k) + solve(arr, k+1, j) + (arr[i-1] * arr[k] * arr[j]);

        ans = min(ans, count);
    }

    return dp[i][j] =  ans;
}

int main() {


    int arr[] = {10, 20, 30}  ;
    int n = sizeof(arr) / sizeof(arr[0]);
    init();

    cout<< solve(arr, 1, n-1) << endl;
}
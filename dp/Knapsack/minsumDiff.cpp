#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int findMin(int set[], int n, int sum) {

    int dp[n+1][sum+1];
    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < sum+1; j++) {
            if(i == 0) {
                dp[i][j] = 0;
            }
            if(j == 0) {
                dp[i][j] = 1;
            }
        }
    }
    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < sum+1; j++) {
            if(set[i-1] <= j) {
                dp[i][j] = dp[i-1][j - set[i-1]] || dp[i-1][j];
            }
            else if(set[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    int diff = INT_MAX;
    for(int i = sum/2; i >= 0; i--) {
        if(dp[n][i]) {
            diff = sum - (2*i);
            break;
        }
    }

    return diff;
}

int main() {

    int arr[] = {3, 1, 4, 2, 2, 1}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum = sum + arr[i];
    }
    cout << "The minimum difference between 2 sets is "
         << findMin(arr, n, sum); 
    return 0; 
}
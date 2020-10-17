#include<iostream>
#include<vector>

using namespace std;

bool isSubsetSum(int set[], int n, int sum) {

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
    return dp[n][sum];
}

int main() {

    int set[] = { 3, 34, 4, 12, 5, 2 }; 
    int sum = 17; 
    int n = sizeof(set) / sizeof(set[0]); 
    if (isSubsetSum(set, n, sum) == true) 
        printf("Found a subset with given sum"); 
    else
        printf("No subset with given sum"); 
    return 0; 
}
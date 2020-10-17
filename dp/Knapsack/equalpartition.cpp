#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool checkSubsetSum(int nums[], int sum, int n) {
        
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
                    dp[i][j] = dp[i-1][j];
                if(nums[i-1] <= j) {
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }              
            }
        }
        
        return dp[n][sum];
    
    }
    
int main() {

    int arr[] = {1, 2, 5}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << n << endl;

    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    cout << arr[-2] << endl;
    if(sum % 2 != 0) {
        cout << "Equal sum partition not possible" << endl;
    }
    else if(checkSubsetSum(arr, sum/2, n)) {
        cout << "Equal sum partition possible" << endl;
    }
    else
        cout << "Equal sum partition not possible" << endl;
    return 0; 
}
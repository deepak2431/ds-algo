#include<iostream>
#include<vector>
#include<string>

using namespace  std;

int dp[50][50];
void init() {
    for(int i = 0; i < 50; i++) {
        for(int j = 0; j < 50; j++) {
            dp[i][j] = -1;
        }
    }
}

int dpKnapsack(int val[], int wt[], int w, int n) {
    
    if(n == 0 || w == 0) {
        return 0;
    }
    if(dp[n][w] != -1) {
        return dp[n][w];
    }
    if(wt[n-1] <= w) {
        return dp[n][w] = max((val[n-1] + dpKnapsack(val, wt, w-wt[n-1], n-1)), dpKnapsack(val, wt, w, n-1));
    }
    else if(wt[n-1] > w) {
        return dp[n][w] = dpKnapsack(val, wt, w, n-1);
    }
}

int recKnapSack(int val[], int wt[], int w, int n) {

    if(n == 0 || w == 0) {
        return 0;
    }
    if(wt[n-1] <= w) {
        return max((val[n-1] + recKnapSack(val, wt, w-wt[n-1], n-1)), recKnapSack(val, wt, w, n-1));
    }
    else if(wt[n-1] > w) {
        return recKnapSack(val, wt, w, n-1);
    }
}

int main() {

    int val[] = { 60, 100, 120 }; 
    int wt[] = { 10, 20, 30 }; 
    int W = 50; 
    init();
    int n = sizeof(val) / sizeof(val[0]); 
    cout << recKnapSack(val, wt, W, n) << endl;
    cout << dpKnapsack(val, wt, W, n); 

    return 0; 
}
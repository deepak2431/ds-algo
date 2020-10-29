// minimum number of partition required to make all sub string plaindrome
#include<iostream>
#include<vector>
#include<string>
#include<climits>
using namespace std;

int dp[502][502];

void init() {
    for(int i = 0; i < 502; i++) {
        for(int j = 0; j < 502; j++) {
            dp[i][j] = -1;
        }
    }
}


bool isPalindrome(string s, int start, int end) {

    while(start <= end) {
        if(s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}
int solve(string s, int i, int j) {
     if(i > j) {
        return 0;
    }
    int ans = INT_MAX;

    if(isPalindrome(s, i, j)) {
        return dp[i][j] = 0;
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    
    for(int k = i; k < j; k++) {
        
        int left, right;
        if(dp[i][k] != -1) {
            left = dp[i][k];
        }
        else {
           left = solve(s, i, k);
           dp[i][k] = left;
        }
        if(dp[k+1][j] != -1) {
            right = dp[k+1][j];
        }
        else {
            right = solve(s, k+1, j);
            dp[k+1][j] = right;
        }
        
        int count = (1 + left + right);

        ans = min(ans, count);
    }

    return dp[i][j] =  ans;
}

int main() {

    init();
    string s = "aba";
    int n = s.size() - 1;
    init();
    //cout<< isPalindrome("madam", 0, 4) << endl;
    cout << solve(s, 0, n) << endl;

}
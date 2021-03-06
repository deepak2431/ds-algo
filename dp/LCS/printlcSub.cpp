//Longest common substring
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

string ans;

void maxSubstr(string s1, string s2, int n, int m) {

    int dp[n+1][m+1];
    int result, start, end;
    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < m+1; j++) {
            if(i == 0  || j == 0) {
                dp[i][j] = 0;
            }
        }
    }
    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < m+1; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                if(dp[i][j] > result) {
                    result = dp[i][j];
                    start = i; 
                    end = j;
                }
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    int i = start, j = end;
    while(i > 0 && j > 0) {
        if(s1[i-1] == s2[j-1]) {
            ans.push_back(s1[i-1]);
            i--;
            j--;
        }
        else  {
            i--;
            j--;
        }
    }
    return;

}

int main() {

    string s1 = "OldSite:GeeksforGeeks.org";
    string s2 = "NewSite:GeeksQuiz.com";  

    maxSubstr(s1, s2, s1.size(), s2.size());
    reverse(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i];
        cout << endl;
}
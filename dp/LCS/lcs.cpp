#include<iostream>
#include<string>

using namespace std;

int dp[50][50];
void init() {
    for(int i = 0; i < 50; i++) {
        for(int j = 0; j < 50; j++) {
            dp[i][j] = -1;
        }
    }
}

int findLcs(string s1, string s2, int n, int m) {

    if(n == 0 || m == 0) {
        return 0;
    }
    if(dp[n][m] == -1) {
        if(s1[n-1] == s2[m-1]) {
        return dp[n][m] = 1 + findLcs(s1, s2, n-1, m-1); 
        }   
        else {
            return dp[n][m] = max(findLcs(s1, s2, n-1, m), findLcs(s1, s2, n, m-1));
        }
    }
}


int findLcsRec(string s1, string s2, int n,int m) {

    if(n==0 || m == 0) {
        return 0;
    }
    if(s1[n-1] == s2[m-1]) {
        return 1 + findLcsRec(s1, s2, n-1, m-1);
    }
    else  {
        return max(findLcsRec(s1, s2, n-1, m), findLcsRec(s1, s2, n, m-1));
    }
}

int main() {

    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";  
    init();

    cout << findLcsRec(s1, s2, s1.size(), s2.size()) << endl;
    cout << findLcs(s1, s2, s1.size(), s2.size()) << endl;


}
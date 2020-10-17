#include <iostream>
#include <string>
#include<algorithm>

using namespace std;

string ans;

void printLcs(string s1, string s2, int n, int m)
{

    int dp[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0)
            {
                dp[i][j] = 0;
            }
            if (j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][m] << endl;

    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans.push_back(s1[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j]) {
                j--;
            }
            else
                i--;
        }
    }
    return;
}

    int main()
    {

        string s1 = "AGTGATG"; 
    string s2 = "GTTAG"; 

        printLcs(s1, s2, s1.size(), s2.size());
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i];
        cout << endl;
    }
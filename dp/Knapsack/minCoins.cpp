#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int findMinCoins(vector<int> coin, long long amount)
{

    long long n = coin.size();
    long long dp[n + 1][amount + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < amount + 1; j++)
        {
            if (i == 0)
            {
                dp[i][j] = INT_MAX - 1;
            }
            if (j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < amount + 1; i++)
    {
        if (i % coin[0] == 0)
        {
            dp[1][i] = i / coin[0];
        }
        else
        {
            dp[1][i] = INT_MAX - 1;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < amount + 1; j++)
        {
            if (coin[i - 1] <= j)
            {
                dp[i][j] = min((dp[i][j - coin[i - 1]]) + 1, dp[i - 1][j]);
            }
            else if(coin[i-1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][amount]; 
}

int main()
{

    vector<int> coins = {1, 5, 10, 20, 100};
    long long n;
    cin >> n;
    cout << findMinCoins(coins, n) << endl;

    return 0;
}
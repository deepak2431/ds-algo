#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <cmath>

using namespace std;

bool checkpower(int n)
{

    if (n == 0)
        return 0;
    while (n != 1)
    {
        if (n % 2 != 0)
            return 0;
        n = n / 2;
    }
    return 1;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        long long int n;
        cin >> n;

        long long int arr[n + 1];
        if (n > 2 && !checkpower(n))
        {
            for (int i = 1; i <= n; i++)
            {
                arr[i] = i;
            }
            arr[1] = 2, arr[2] = 3, arr[3] = 1;
            for (int i = 4; i <= n; i++)
            {
                if (checkpower(i))
                {
                    swap(arr[i], arr[i + 1]);
                    i++;
                }
            }
        }

        if (n == 1)
        {
            cout << 1 << endl;
        }
        else if (checkpower(n))
        {
            cout << -1 << endl;
        }
        else
        {
            for (int i = 1; i <= n; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
}
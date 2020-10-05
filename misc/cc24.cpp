//Replesx
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        long long int n, x, p, k;
        cin >> n >> x >> p >> k;

        vector<long long int> arr;

        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            arr.push_back(num);
        }

        bool found = false;
        int ans = -1, pos = -1, count = 0, i;
        sort(arr.begin(), arr.end());
        for (i = 0; i < arr.size(); i++)
        {
            if (arr[i] == x) {
                 pos = i;
            }
        }
        int p_small = arr[p - 1];
        if (p_small == x)
        {
            ans = 0;
            found = true;
        }
        else if(pos > -1) {
            ans = p - (pos+1);
            found = true;
        }
        if(found)
            cout << ans << endl;
        else
        {
            cout << -1 << endl;
        }
        
    }
}

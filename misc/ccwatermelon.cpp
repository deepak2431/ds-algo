#include<iostream>
#include<vector>

using namespace std;

int main() {

    int t;
    cin >> t;
    while(t--) {

        long long int n;
        cin >> n;
        vector<long long int> arr;
        for(int i = 0; i < n; i++) {
            long long int num;
            cin >> num;
            arr.push_back(num);
        }

        long long int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
        }
        if(sum >= 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        
    }
}
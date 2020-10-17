#include<iostream>
#include<vector>

using namespace  std;

int main () {

    long long int n, q;
    cin >> n >> q;
    
    vector<long long int> arr;

    for(int i = 0; i < n; i++) {
        long long int num;
        cin >> num;
        arr.push_back(num);
    }

    vector<long long int> prefix(arr.size(), 0);
    prefix[0] = arr[0];
    for(int i = 1; i < arr.size(); i++) {
        prefix[i] = prefix[i-1] + arr[i];
    }

    for(long long int i = 0; i < q; i++) {

        long long int a, b;
        cin >> a >> b;

        if(a == b)
            cout << arr[a-1] << endl;
        else if(a > 1)
            cout << prefix[b-1] - prefix[a-2]<< endl;
        else
            cout << prefix[b-1] << endl;
        
    }

    return 0;
}

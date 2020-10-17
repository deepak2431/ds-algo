// Find equillibirium index
#include<iostream>
#include<vector>
using namespace std;
int main()
 {
	//code
	int t;
	cin >> t;
	while(t--) {
	vector<long long> arr;
	long long n;
	cin >> n;
	for(int i = 0; i < n; i++) {
	    long long num;
	    cin >> num;
	    arr.push_back(num);
	}
	vector<int>preSum(n, 0);
	preSum[0] = arr[0];
	for(int i = 1; i < n; i++) {
	    preSum[i] = preSum[i-1] + arr[i];
	}
	int totalSum = 0, leftSum, rightSum;
	for(int i = 0; i < n; i++) {
	    totalSum += arr[i];
	}
	bool found = false;
    int ans = 0;
	for(int i = 0; i < n; i++) {
	    leftSum = preSum[i] - arr[i];
	    rightSum = totalSum - preSum[i];
	    if(leftSum == rightSum) {
            ans = i;
            found = true;
	        break;
	    }
	}
	if(found)
	    cout << ans+1 << endl;
	else
	    cout << -1 << endl;
}
	return 0;
}
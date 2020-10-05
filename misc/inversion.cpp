#include<iostream>
#include<vector>
using namespace std;

int merge(vector<long long int>&arr, vector<long long int>&temp, int left, int mid, int right) {
    
    int invCount = 0;
    int i = left, j = mid, k = left;
    while((i <= mid-1) && (j <= right)) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            invCount = invCount + (mid - i);
        }
    }
    while(i <= mid-1) {
        temp[k++] = arr[i++];
    }
    
    while(j <= right) {
        temp[k++] = arr[j++];
    }
    for (i = left; i <= right; i++) 
		arr[i] = temp[i]; 
    
    return invCount;
}

int mergeSort(vector<long long int>&arr, vector<long long int> &temp, int left, int right) {
    
    int mid, invCount = 0;
    if(right > left) {
        
        int mid = (right + left) / 2;
        
        invCount += mergeSort(arr, temp, left, mid);
        invCount += mergeSort(arr, temp, mid+1, right);
        
        invCount += merge(arr, temp, left, mid+1, right);
    }
    
    return invCount;
}
int findInversion(vector<long long int>&arr, int left, int right) {
    
    vector<long long int>temp(arr.size(), -1);
    return mergeSort(arr, temp, 0, arr.size()-1);
}
int main()
 {
	//code
	int t;
	cin >> t;
	while(t--) {
	    
	    long long int n;
	    cin >> n;
	    vector<long long int>arr;
	    for(int i = 0; i < n; i++) {
	        int num;
	        cin >> num;
	        arr.push_back(num);
	    }
	    
	    cout << findInversion(arr, 0, arr.size() - 1) << endl;
	}
	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

void findSoln(vector<long long int> &query, long long int n, long long int k) {

	long long int remQuery = 0;
    bool flag = false;
        for(long long int i = 0; i < n; i++){
            if(query[i] + remQuery < k){
                cout << i+1 << endl;
                flag = true;
                break;
            }
            remQuery = query[i] + remQuery - k;
        }
        if(!flag){
            cout<< (n + remQuery/k + 1) <<endl;
		}
}

int main() {

    int t;
    cin>>t;

    while(t--){
        long long int n, k;
        cin>>n>>k;
        vector<long long int> query;
        for(long long int i = 0; i < n; i++) {
			long long int num;
			cin >> num;
			query.push_back(num);
		}
		findSoln(query, n, k);
    }

	return 0;
}
#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void calStockSpan(vector<int> price, vector<int> &span) {
    
    stack<int> st;
    st.push(0);
    span.push_back(1);
    
    for(int i = 1; i < price.size(); i++) {
        
        while(!st.empty() && price[st.top()] <= price[i])
            st.pop();
        
        int val = (st.empty()) ? (i + 1) : (i - st.top());
        span.push_back(val);
        
        st.push(i);
    }
}

int main()
{
	//code
	
	int t;
	cin >> t;
	while(t--) {
	    
	    vector<int> price, span;
	    int n;
	    cin >> n;
	    for(int i = 0; i < n; i++) {
	        int p;
	        cin >> p;
	        price.push_back(p);
	    }
	    calStockSpan(price, span);
	    
	    for(int i = 0; i < span.size(); i++) {
	        cout << span[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}
#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

unordered_set<string> st;

void generateSubsequence(string s) {
    
    for(int i = 0; i < s.size(); i++) {
        for(int j = s.size(); j > i; j--) {
            string sub = s.substr(i, j);
            st.insert(sub);
            
            for(int k = 1; k < sub.size() - 1; k++) {
                
                string sb = sub;
                sb.erase(sb.begin() + k);
                generateSubsequence(sb);
            }
        }
    }
    
}
int main()
 {
	//code
	int t;
	cin >> t;
	while(t--) {
	    
	    string s;
	    cin >> s;
	    generateSubsequence(s);
	    
	    for(auto it : st)
	        cout << it << " ";
	}
	return 0;
}
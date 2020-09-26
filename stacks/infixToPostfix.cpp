#include<iostream>
#include<stack>
#include<ctype.h>

using namespace std;

//function to check the precedence of operators
int prec(char c) {

    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string s) {

    stack<char> st;
    st.push('N');
    string ans;

    for(int i = 0; i < s.size(); i++) {

        if(isalpha(s[i]))
            ans.push_back(s[i]);
        
        else if(s[i] == '(')
            st.push(s[i]);
        
        else if(s[i] == ')') {

            while(st.top() != 'N' && st.top() != '(') {
                char c = st.top();
                st.pop();
                ans.push_back(c);
            }
            if(st.top() == '(') {
                char c = st.top();
                st.pop();
            }
        }
        else {
            while(st.top() != 'N' && prec(s[i]) <= prec(st.top())) {
                char c = st.top();
                ans.push_back(c);
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(st.top() != 'N') {
        char c = st.top();
        st.pop();
        ans.push_back(c);
    }

    return ans;
}

int main() {

    string str = "a+b*(c^d-e)^(f+g*h)-i";

    cout << infixToPostfix(str) << endl;

    return 0;
}
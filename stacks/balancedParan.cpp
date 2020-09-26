#include <iostream>
#include <stack>
using namespace std;

bool checkIsBalanced(string s)
{

    stack<char> st;
    char x;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
            continue;
        }
        if (st.empty())
            return false;

        switch (s[i])
        {

        case ')':
            x = st.top();
            st.pop();
            if (x == '{' || x == '[')
                return false;

            break;

        case '}':
            x = st.top();
            st.pop();
            if (x == '(' || x == '[')
                return false;

            break;

        case ']':
            x = st.top();
            st.pop();
            if (x == '(' || x == '{')
                return false;
            break;
        }
    }

    return (st.empty());
}
int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {

        string s;
        cin >> s;

        if (checkIsBalanced(s))
            cout << "balanced" << endl;
        else
            cout << "not balanced" << endl;
    }
    return 0;
}
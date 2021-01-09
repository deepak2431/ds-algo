#include<iostream>
#include<string>

using namespace std;

bool checkSub(string str, string sub, int i, int n, int j, int m) {
    
    if(j == m) {
        return 1;
    }
    if(i == n && j != m) {
         return 0;
    }
    if(str[i] == sub[j]) {
        return checkSub(str, sub, i+1, n, j+1, m);
    }
    else {
        return checkSub(str, sub, i+1, n, j, m);
    }
}

int main() {

    
    string str = "batman";
    string sub = "bat";
    if(checkSub(str, sub, 0, str.size()-1, 0, sub.size()-1))
        cout << "Subsequence exists" << endl;
    else
        cout << "Subsequence doesn't exists" << endl;
}
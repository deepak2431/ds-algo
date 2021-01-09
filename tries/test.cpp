#include<iostream>
void abc(string s) {
    if(s[0] == '\0') {
        return;
    }
    abc(s+1);
    abc(s+1);
    cout << s[0];
}

int main() {
    abc("mysql");
    return 0;
}
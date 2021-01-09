#include<iostream>
#include<string>

using namespace std;

void print(string str, int n) {
    if(n == 0) {
        cout << str[n];
        return;
    }
    cout << str[n];
    print(str, n-1);
    return;
}

int main() {

    print("Deepak", 5);
}
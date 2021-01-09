#include<iostream>
#include<string>

using namespace std;

bool checkPalindrome(string str, int i, int n) {

    if(i == n/2)
        return 1;
    if(str[i] != str[n-i-1]) {
        cout << str[i];
        return 0;
    }
    return checkPalindrome(str, i+1, n);
}

int main() {

    if(checkPalindrome("geeksforgeeks", 0, 13))
        cout << "Yes, the given string is palindrome" << endl;
    else
        cout << "The given string is not palindrome" << endl;
}
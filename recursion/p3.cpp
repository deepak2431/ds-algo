#include<iostream>
#include<string>

using namespace std;

int sum = 0;
int  findSum(int n) {
    if(n == 0) 
        return 0;
    sum  = sum + (n%10);
    findSum(n/10);
    //return sum;
    
}

int main() {

    findSum(123);
    
    cout << sum << endl;
}
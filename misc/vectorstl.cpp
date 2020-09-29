#include<iostream>
#include<vector>

using namespace std;

void insertElem(vector<string> &perm) {

    perm.push_back("Deepak");
}

int main() {

    vector<string> perm;

    perm.push_back("Hi");
    perm.push_back("ghj");

    insertElem(perm);
    perm.pop_back();

    for(int i = 0; i < perm.size(); i++)
        cout << perm[i] << endl;
}
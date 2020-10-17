#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void insertElem(vector<string> &perm) {

    perm.push_back("Deepak");
}

int main() {

    vector<string> perm;

    perm.push_back("mousepad");
    perm.push_back("monitor");
    perm.push_back("mobile");
    perm.push_back("moneypot");

    auto it = perm.begin();
    sort(perm.begin(), perm.end());
    string searchWord = "mouse", pat;

    vector<vector<string>> res;

    for(char c:searchWord) {
            pat+=c;
            vector<string> step;
            it = lower_bound(it, perm.end(), pat);
            cout << *it << endl;
            for(int i=0; i<3; i++)
            {
                if(it+i==perm.end()) break;
                string& n=*(it+i);
                cout << "I am" << n << endl;
                if(pat!=n.substr(0,pat.size())) break;
                cout << n << endl;
                step.push_back(n);
            }
            for(int i = 0; i < step.size();  i++)
                cout << step[i] << " ";
            cout << endl;
            //res.push_back(step);
    }

    //cout << res.size() << endl;

    insertElem(perm);
    perm.pop_back();
}
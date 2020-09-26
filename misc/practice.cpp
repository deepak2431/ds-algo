#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<unordered_map>

using namespace std;

bool checkCommonSubstring(string s1, string s2) {

    unordered_map<char, int> ump1, ump2;

    for(int i = 0; i < s1.size(); i++) {
        if(ump1.find(s1[i]) == ump1.end())
            ump1.insert(make_pair(s1[i], 1));
        else
        {
            ump1[s1[i]]++;
        }
        
    }
      for(int i = 0; i < s2.size(); i++) {
        if(ump2.find(s2[i]) == ump2.end()) {
             ump2.insert(make_pair(s2[i], 1));
        }
        else
        {
            ump2[s2[i]]++;
        }
        
    }

    for(auto &it1: ump1) {
        char c1 = it1.first;
        for(auto &it2 : ump2) {
            if(it2.first == c1 && it2.second >= 1) {
                cout << it2.first << endl;
                return true;

            }
        }

    }

    return false;


}

int main() {

    if(checkCommonSubstring("Hello", "World"))
        cout << "there is common substring" << endl;
    else
    {
        cout << "there is no common substring" << endl;
    }
    
}
#include<iostream>
#include<vector>
#include<string>

using namespace std;
    
void computeLpsArr(string pat, int pat_size, int *lps) {
        
        lps[0] = 0;
        int len = 0, i = 1;
        
        while (i < pat_size) {
            if(pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if(len != 0)
                    len = lps[len-1];
                
                else if(len == 0) {
                    lps[i] = 0;
                    i++;
                }
            }  
        }
        
    }
    
    bool checkPattern(string str, string pat) {
        
        int str_len = str.size();
        int pat_len = pat.size(), i = 0, j = 0;
        int lps[pat_len];
        
        computeLpsArr(pat, pat_len, lps);
        
        while (i < str_len) {
            
            if(str[i] == pat[j]) {
                i++;
                j++;
            }
            else {
                if(j != 0)
                    j = lps[j-1];
                else
                    i++;
            }
            if(j == pat_len)
                return true;
        }
        return false;
    } 
    
    void generatePerm(vector<string> &perm, string str, int l, int r) {
        
        if(l == r) {

            cout << str << endl;
            perm.push_back(str);


        }        
        
        else {
            for(int i = l; i <= r; i++) {
                swap(str[l], str[i]);
                generatePerm(perm, str, l+1, r);
                swap(str[l], str[i]);
            }
        }
    }
    
    bool checkInclusion(string s1, string s2) {
        
        vector<string> perm;
        generatePerm(perm, s1, 0, s1.size() - 1);
        cout << perm.size() << endl;

        
        for(int i = 0; i < perm.size(); i++) {
            if(checkPattern(s2, perm[i])) {
                return true;

            }
        }
        
        return false;
        
    }


int main() {

    if(checkInclusion("ab","eidbaooo" ))
        cout<< "True" << endl;
    else
        cout << "false" << endl;

return 0;
}
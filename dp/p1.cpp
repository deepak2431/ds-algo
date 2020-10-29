//Longest palindromic substring
class Solution {
public:
    
    string longestPalindrome(string s) {
        
        if(s.size() <= 1) {
            return s;
        }
        int len = s.size();
        int start, end, i = 0;
        int maxLen = 1;
        int currInd = 0;
        while(i < s.size()) {
            start = i;
            end = i;
            
            while(end+1 < s.size() && s[end] == s[end+1]) {
                end++;
            }
            i = end+1;
            
            while(start - 1 >= 0 && end+1 < s.size() && s[start-1] == s[end+1]) {
                start--;
                end++;
            }
            
            int currLen = end - start + 1;
            if(currLen > maxLen) {
                maxLen = currLen;
                currInd = start;
            }
        }
        
        return s.substr(currInd, maxLen);
        
    }
};
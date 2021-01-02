class Solution {
public:
    vector<char> str;
    void solve(int &tempStart, int &tempEnd, int v) {
        int i, j;
        i = j = v;
        while(i >= 0 && j < str.size() && str[i] == str[j]) {
            tempStart = i;
            tempEnd = j;
            i--; j++;
        }
    }
    string longestPalindrome(string s) {
        if(s.length() == 0) {
            return s;
        }
        
        for(int i=0; i<s.length(); i++) {
            str.push_back(s[i]);
            str.push_back('$');
        }
        int maxStart=0, maxEnd=0;
        for(int i=0; i<str.size(); i++) {
            int tempStart=i, tempEnd=i;
            solve(tempStart, tempEnd, i);
            if(maxEnd-maxStart < tempEnd-tempStart) {
                maxEnd = tempEnd;
                maxStart = tempStart;
            }
        }
        string ans="";
        for(int i=maxStart; i<=maxEnd; i++) {
            if(str[i] != '$') ans += str[i];
        }
        return ans;
    }
};

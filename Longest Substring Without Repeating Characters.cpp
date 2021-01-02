class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        unordered_map<char, int> mem;
        mem[s[0]] = 0;
        int start=0, i=1, maxLen=INT_MIN;
        while(i < s.length()) {
            if(mem.find(s[i]) != mem.end() && mem[s[i]] >= start) {
                maxLen = max(maxLen, i-start);
                start=mem[s[i]]+1;
            } 
            mem[s[i]] = i;
            i++;
        }
        maxLen = max(maxLen, i-start);
        return maxLen;
    }
};

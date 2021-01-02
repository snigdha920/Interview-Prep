class Solution {
public:
    int firstUniqChar(string s) {
        int count[26];
        memset(count, 0, sizeof(count));
        int n = s.length();
        for(int i=0; i<n; i++) {
            count[s[i]-'a']++;
        }
        int ans=-1;
        for(int i=0; i<n; i++) {
            if (count[s[i]-'a'] == 1) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() == 0) return 0;
        int i, ans = -1;
        int needleLength = needle.length();
        int haystackLength = haystack.length();
        if(haystackLength < needleLength) return -1;
        for(int i=0; i<haystack.length(); i++) {
            int j=0;
            while(i+j < haystackLength && j < needleLength && needle[j] == haystack[i+j]) {
                // cout << needle[j] << ", " << haystack[i+j] << endl;
                j++;
            }
            if(j == needleLength) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};

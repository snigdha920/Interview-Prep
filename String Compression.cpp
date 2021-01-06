class Solution {
public:
    int compress(vector<char>& chars) {
        int len=chars.size();
        int i=0, j=0;
        while(i < len) {
            int count=1;
            while(i < len-1 && chars[i] == chars[i+1]) {
                count++;
                i++;
            }
            chars[j++] = chars[i++];
            if(count == 1) continue;
            string cnt = to_string(count);
            for(int k=0; k<cnt.length(); k++) chars[j++] = cnt[k];
        }
        return j;
    }
};

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        if(n == 0) {
            cout << "";
            return;
        }
        for(int i=0; i<=(n-1)/2; i++) {
            swap(s[i], s[n-1-i]);
        }
        for(int i=0; i<n; i++) {
            cout << s[i];
        }
    }
};

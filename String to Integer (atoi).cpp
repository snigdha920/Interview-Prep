class Solution {
public:
    int myAtoi(string s) {
        if(s.length() == 0) return 0;
        int n = s.length(), i=0;
        while(i<n && s[i] == ' ') i++;
        if(i == n) return 0;
        if(s[i] != '+' && s[i] != '-' && s[i]-'0' < 0 && s[i]-'0' > 9) return 0;
        if(i == n-1) {
            if(s[i]-'0' >= 0 && s[i]-'0' <= 9) return s[i]-'0';
            else return 0;
        }
        bool flag=1;
        if(s[i] == '-') flag=0;
        if(s[i] == '+' || s[i]=='-') i++;
        long long int num = 0;
        long long int ten=1;
        while(i < n && s[i]-'0' >= 0 && s[i]-'0' <= 9) {
            num = num*10 + (s[i]-'0');
            i++;
            if(num > INT_MAX) {
                if(flag) return INT_MAX;
                else return INT_MIN;
            }
        }
        // cout << "num is " << num << endl;
        if(flag) return num;
        else return -1*num;
    }
};

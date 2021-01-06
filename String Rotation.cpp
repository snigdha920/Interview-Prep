class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.length() != B.length()) return false;
        B.append(B);
        return B.find(A) != string::npos;
    }
};

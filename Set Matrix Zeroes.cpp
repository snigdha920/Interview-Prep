class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> zr, zc;
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[i].size(); j++) {
                if(matrix[i][j] == 0) {
                    zr.insert(i);
                    zc.insert(j);
                }
            }
        }
        for(int i=0; i<matrix.size(); i++) {
            if(zr.find(i) != zr.end()) {
                for(int j=0; j<matrix[i].size(); j++) matrix[i][j] = 0;
            }
        }
        for(int j=0; j<matrix[0].size(); j++) {
            if(zc.find(j) != zc.end()) {
                for(int i=0; i<matrix.size(); i++) matrix[i][j] = 0;
            }
        }
    }
};

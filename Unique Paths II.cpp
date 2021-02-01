class Solution {
public:
    vector<vector<int>>grid;
    int paths[110][110];
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(paths, -1, sizeof(paths));
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        grid.resize(m, vector<int>(n));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                grid[i][j] = obstacleGrid[i][j];
            }
        }
        return calcPath(m-1, n-1);
    }
    int calcPath(int r, int c) {
        if(r < 0 || c < 0) return 0;
        if(grid[r][c] == 1) return 0;
        if(r == 0 && c == 0) return 1;
        if(paths[r][c] != -1) return paths[r][c];
        paths[r][c] = calcPath(r, c-1) + calcPath(r-1, c);
        return paths[r][c];
    }
};

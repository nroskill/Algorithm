/**
 * https://leetcode.com/problems/unique-paths-ii/
 * By Nroskill
 * runtime 3 ms
 * language cpp
 */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m < 1)
            return 0;
        int n = obstacleGrid[0].size();
        vector<int> cal(obstacleGrid[0]);
        cal[0] = obstacleGrid[0][0] == 0 ? 1 : 0;
        for(int i = 1; i < n; i++)
            cal[i] = (obstacleGrid[0][i] == 0 && cal[i - 1] == 1 ? 1 : 0);
        for(int i = 1; i < m; i++) {
            cal[0] = (obstacleGrid[i][0] == 0 && cal[0] == 1 ? 1 : 0);
            for(int j = 1; j < n; j++)
                cal[j] = (obstacleGrid[i][j] == 0 ? cal[j] + cal[j - 1] : 0);
        }
        return cal[n - 1];
    }
};
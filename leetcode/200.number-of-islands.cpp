/**
 * https://leetcode.com/problems/number-of-islands/
 * By Nroskill
 * runtime 6 ms
 * language cpp
 */

class Solution {
public:
    void landToWater(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        landToWater(grid, i + 1, j);
        landToWater(grid, i - 1, j);
        landToWater(grid, i, j + 1);
        landToWater(grid, i, j - 1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == '1') {
                    result++;
                    landToWater(grid, i, j);
                }
        return result;
    }
};
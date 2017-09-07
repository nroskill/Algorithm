/**
 * https://leetcode.com/problems/island-perimeter/
 * By Nroskill
 * runtime 95 ms
 * language cpp
 */

class Solution {
public:
    void find(int& perimeter, vector<vector<int>>& grid, int x, int y) {
        perimeter += 4;
        grid[x][y] = 2;
        if( x > 0 && grid[x - 1][y] != 0) {
            perimeter -= 1;
            if(grid[x - 1][y] == 1)
                find(perimeter, grid, x - 1, y);
        }
        if( x < grid.size() - 1&& grid[x + 1][y] != 0) {
            perimeter -= 1;
            if(grid[x + 1][y] == 1)
                find(perimeter, grid, x + 1, y);
        }
        if( y > 0 && grid[x][y - 1] != 0) {
            perimeter -= 1;
            if(grid[x][y - 1] == 1)
                find(perimeter, grid, x, y - 1);
        }
        if( y < grid[x].size() - 1&& grid[x][y + 1] != 0) {
            perimeter -= 1;
            if(grid[x][y + 1] == 1)
                find(perimeter, grid, x, y + 1);
        }
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[i].size(); j++)
                if(grid[i][j]) {
                    find(perimeter, grid, i, j);
                    return perimeter;
                }
        return 0;
    }
};
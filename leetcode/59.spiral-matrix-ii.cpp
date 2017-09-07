/**
 * https://leetcode.com/problems/spiral-matrix-ii/
 * By Nroskill
 * runtime 3 ms
 * language cpp
 */

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int i = 1;
        int left = 0, right = n - 1, up = 0, down = n - 1;
        while(true) {
            for(int j = left; j <= right; j++)
                result[up][j] = i++;
            if(++up > down)
                break;
            
            for(int j = up; j <= down; j++)
                result[j][right] = i++;
            if(--right < left)
                break;
            
            for(int j = right; j >= left; j--)
                result[down][j] = i++;
            if(--down < up)
                break;
            
            for(int j = down; j >= up; j--)
                result[j][left] = i++;
            if(left++ > right)
                break;
        }
        return result;
    }
};
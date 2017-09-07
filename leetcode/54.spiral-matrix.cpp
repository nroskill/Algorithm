/**
 * https://leetcode.com/problems/spiral-matrix/
 * By Nroskill
 * runtime 0 ms
 * language cpp
 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0)
            return vector<int>();
        vector<int> result(matrix.size() * matrix[0].size(), 0);
        int left = 0, right = matrix[0].size() - 1, up = 0, down = matrix.size() - 1;
        int x = 0, y = 0, i = 0;
        while(left <= right && up <= down) {
            for(int j = left; j <= right; j++)
                result[i++] = matrix[up][j];
            up++;
            if(up > down)
                break;
            
            for(int j = up; j <= down; j++)
                result[i++] = matrix[j][right];
            right--;
            if(left > right)
                break;
                
            for(int j = right; j >= left; j--)
                result[i++] = matrix[down][j];
            down--;
            if(up > down)
                break;
            
            for(int j = down; j >= up; j--)
                result[i++] = matrix[j][left];
            left++;
        }
        return result;
    }
};
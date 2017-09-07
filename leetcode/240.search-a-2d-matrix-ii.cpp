/**
 * https://leetcode.com/problems/search-a-2d-matrix-ii/
 * By Nroskill
 * runtime 66 ms
 * language cpp
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0 || target < matrix[0][0] || target > matrix[matrix.size() - 1][matrix[0].size() - 1])
            return false;
        int r = matrix.size() - 1;
        int c = 0;
        while(r >= 0 && c < matrix[0].size()) {
            if(matrix[r][c] == target)
                return true;
            if(matrix[r][c] < target)
                c++;
            else
                r--;
        }
        return false;
    }
};
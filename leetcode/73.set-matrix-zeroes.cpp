/**
 * https://leetcode.com/problems/set-matrix-zeroes/
 * By Nroskill
 * runtime 56 ms
 * language cpp
 */

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() < 1)
            return;
        int firstRowState = 1;
        int firstColState = 1;
        for(int i = 0; i < matrix.size(); i++)
            if(matrix[i][0] == 0) {
                firstColState = 0;
                break;
            }
        for(int i = 0; i < matrix[0].size(); i++)
            if(matrix[0][i] == 0) {
                firstRowState = 0;
                break;
            }
        
        for(int i = 1; i < matrix.size(); i++)
            for(int j = 1; j < matrix[0].size(); j++)
                if(matrix[i][j] == 0)
                    matrix[0][j] = matrix[i][0] = 0;
        
        for(int i = matrix.size() - 1; i >= 0; i--)
            for(int j = matrix[0].size() - 1; j >= 0; j--)
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
        
        if(firstRowState == 0)
            for(int i = 0; i < matrix[0].size(); i++)
                matrix[0][i] = 0;
        if(firstColState == 0)
            for(int i = 0; i < matrix.size(); i++)
                matrix[i][0] = 0;
    }
};
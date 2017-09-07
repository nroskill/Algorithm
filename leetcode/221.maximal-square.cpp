/**
 * https://leetcode.com/problems/maximal-square/
 * By Nroskill
 * runtime 9 ms
 * language cpp
 */

class Solution {
public:
    int test(vector<vector<char>>& matrix, int x, int y) {
        if(matrix[x][y] == '0')
            return 0;
        int l = 2;
        for(;x + l - 1 < matrix.size() && y + l - 1 < matrix[0].size(); l++)
            for(int i = 0; i < l; i++)
                if(matrix[x + l - 1][y + i] == '0' || matrix[x + i][y + l - 1] == '0')
                    return l - 1;
        return l - 1;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int l = 0;
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                l = max(l, test(matrix, i, j));
        return l * l;
    }
};
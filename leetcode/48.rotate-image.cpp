/**
 * https://leetcode.com/problems/rotate-image/
 * By Nroskill
 * runtime 9 ms
 * language cpp
 */

class Solution {
public:
    void doIt(vector<vector<int>>& matrix, int x, int y) {
        int t = matrix[x][y];
        matrix[x][y] = matrix[matrix.size() - 1 - y][x];
        matrix[matrix.size() - 1 - y][x] = matrix[matrix.size() - 1 - x][matrix.size() - 1 - y];
        matrix[matrix.size() - 1 - x][matrix.size() - 1 - y] = matrix[y][matrix.size() - 1 - x];
        matrix[y][matrix.size() - 1 - x] = t;
    }
    
    void rotate(vector<vector<int>>& matrix) {
        int t;
        for(int i = 0; i < matrix.size() / 2; i++)
            for(int j = i; j < matrix.size() - i - 1; j++)
                doIt(matrix, i, j);
    }
};
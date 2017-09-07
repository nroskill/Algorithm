/**
 * https://leetcode.com/problems/triangle/
 * By Nroskill
 * runtime 9 ms
 * language cpp
 */

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n == 1)
            return triangle[0][0];
        for(int i = 1; i + 1 < n; i++) {
            triangle[i][0] += triangle[i - 1][0];
            triangle[i][i] += triangle[i - 1][i - 1];
            for(int j = 1; j < i; j++)
                triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
        }
        triangle[n - 1][0] += triangle[n - 2][0];
        triangle[n - 1][n - 1] += triangle[n - 2][n - 2];
        int result = min(triangle[n - 1][0], triangle[n - 1][n - 1]);
        for(int i = 1; i < n - 1; i++) {
            triangle[n - 1][i] += min(triangle[n - 2][i - 1], triangle[n - 2][i]);
            result = min(result, triangle[n - 1][i]);
        }
        return result;
    }
};
/**
 * https://leetcode.com/problems/pascals-triangle/
 * By Nroskill
 * runtime 3 ms
 * language cpp
 */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows == 0)
            return result;
        for(int i = 1; i <= numRows; i++) {
            vector<int> t(i, 1);
            for(int j = 1; j < i - 1; j++)
                t[j] = result[i - 2][j - 1] + result[i - 2][j];
            result.push_back(t);
        }
        return result;
    }
};
/**
 * https://leetcode.com/problems/reshape-the-matrix/
 * By Nroskill
 * runtime 36 ms
 * language cpp
 */

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(nums.size() < 1 || r * c != nums.size() * nums[0].size())
            return nums;
        vector<vector<int>> result(r, vector<int>(c, 0));
        for(int i = 0; i < r * c; i++)
            result[i / c][i % c] = nums[i / nums[0].size()][i % nums[0].size()];
        return result;
    }
};
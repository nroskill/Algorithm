/**
 * https://leetcode.com/problems/subsets/
 * By Nroskill
 * runtime 6 ms
 * language cpp
 */

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size() == 0)
            return vector<vector<int>>(1, vector<int>());
        int x = nums[nums.size() - 1];
        nums.pop_back();
        auto result = subsets(nums);
        int l = result.size();
        for(int i = 0; i < l; i++) {
            auto t(result[i]);
            t.push_back(x);
            result.push_back(t);
        }
        return result;
    }
};
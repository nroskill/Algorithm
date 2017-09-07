/**
 * https://leetcode.com/problems/permutations/
 * By Nroskill
 * runtime 13 ms
 * language cpp
 */

class Solution {
public:
    vector<vector<int>> cal(vector<int> nums, int index) {
        vector<vector<int>> result;
        if(index == 0)
            result.push_back(nums);
        for(int i = 0; i <= index; i++) {
            swap(nums[index], nums[i]);
            auto x = cal(vector<int>(nums.begin(), nums.end()), index - 1);
            result.insert(result.end(), x.begin(), x.end());
            swap(nums[index], nums[i]);
        }
        return result;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        return cal(nums, nums.size() - 1);
    }
};
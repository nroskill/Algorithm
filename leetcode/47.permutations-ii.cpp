/**
 * https://leetcode.com/problems/permutations-ii/
 * By Nroskill
 * runtime 32 ms
 * language cpp
 */

class Solution {
public:
    void cal(vector<int>& nums, int index, vector<vector<int>>& result) {
        set<int> filter;
        if(index >= nums.size())
            result.push_back(nums);
        
        for(int i = index; i < nums.size(); i++) {
            if(filter.find(nums[i]) != filter.end())
                continue;
            filter.insert(nums[i]);
            swap(nums[index], nums[i]);
            cal(nums, index + 1, result);
            swap(nums[index], nums[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        cal(nums, 0, result);
        return result;
    }
};
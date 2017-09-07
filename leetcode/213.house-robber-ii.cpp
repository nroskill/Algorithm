/**
 * https://leetcode.com/problems/house-robber-ii/
 * By Nroskill
 * runtime 3 ms
 * language cpp
 */

class Solution {
public:
    int helper(vector<int>& nums, int start, int end) {
        if(start + 1 > end)
            return nums[start];
        int prev = nums[start];
        int cur = max(prev, nums[start + 1]);
        for(int i = start + 2; i <= end; i++) {
            prev = max(prev + nums[i], cur);
            swap(cur, prev);
        }
        return cur;
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        return max(helper(nums, 0, nums.size() - 2), helper(nums, 1, nums.size() - 1));
    }
};
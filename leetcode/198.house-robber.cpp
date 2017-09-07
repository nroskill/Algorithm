/**
 * https://leetcode.com/problems/house-robber/
 * By Nroskill
 * runtime 0 ms
 * language cpp
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int helper1 = nums[0];
        if(nums.size() == 1)
            return helper1;
        int helper2 = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++) {
            helper1 = max(helper1 + nums[i], helper2);
            swap(helper1, helper2);
        }
        return max(helper1, helper2);
    }
};
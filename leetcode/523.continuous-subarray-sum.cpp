/**
 * https://leetcode.com/problems/continuous-subarray-sum/
 * By Nroskill
 * runtime 39 ms
 * language cpp
 */

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() < 2)
            return false;
        for(int i = 0; i < nums.size() - 1; i++)
            if(nums[i] == 0 && nums[i + 1] == 0)
                return true;
        if(k == 0)
            return false;
        unordered_set<int> pool;
        pool.insert(0);
        int cur = nums[0];
        cur %= k;
        if(cur)
            pool.insert(cur);
        for(int i = 1; i < nums.size(); i++) {
            cur += nums[i];
            cur %= k;
            if(pool.find(cur) != pool.end())
                return true;
            pool.insert(cur);
        }
        return false;
    }
};
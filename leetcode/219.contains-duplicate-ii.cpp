/**
 * https://leetcode.com/problems/contains-duplicate-ii/
 * By Nroskill
 * runtime 26 ms
 * language cpp
 */

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> pool;
        for(int i = 0; i < nums.size() && i <= k; i++) {
            auto it = pool.find(nums[i]);
            if(it != pool.end())
                return true;
            else
                pool.insert(nums[i]);
        }
        for(int i = 0; i + k + 1 < nums.size(); i++) {
            pool.erase(pool.find(nums[i]));
            auto it = pool.find(nums[i + k + 1]);
            if(it != pool.end())
                return true;
            else
                pool.insert(nums[i + k + 1]);
        }
        return false;
    }
};
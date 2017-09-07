/**
 * https://leetcode.com/problems/contains-duplicate-iii/
 * By Nroskill
 * runtime 16 ms
 * language cpp
 */

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size() < 2 || k == 0)
            return false;
        multiset<long> window;
        window.insert(nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            auto temp = window.lower_bound((long)nums[i] - t);
            if(temp != window.end() && *temp - nums[i] <= t)
               return true;
            if(i >= k)
                window.erase(window.find(nums[i - k]));
            window.insert(nums[i]);
        }
        return false;
    }
};
/**
 * https://leetcode.com/problems/max-consecutive-ones/
 * By Nroskill
 * runtime 39 ms
 * language cpp
 */

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0, current = -1, i;
        for(i = 0; i < nums.size(); i++)
            if(nums[i] == 0) {
                max = max > i - current - 1? max : i - current - 1;
                current = i;
            }
        return max > i - current - 1? max : i - current - 1;
    }
};
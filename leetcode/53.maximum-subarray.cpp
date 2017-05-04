/**
 * https://leetcode.com/problems/maximum-subarray/
 * By Nroskill
 * runtime 12 ms
 * language cpp
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int start = 0, end = nums.size() - 1, result = 0x80000001;
        for(int accumulation = 0, i = 0; i < nums.size(); i++) {
            accumulation += nums[i];
            result = max(accumulation, result);
            accumulation = max(0, accumulation);
        }
        return result;
    }
};
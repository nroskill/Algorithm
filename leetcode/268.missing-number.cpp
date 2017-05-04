/**
 * https://leetcode.com/problems/missing-number/
 * By Nroskill
 * runtime 22 ms
 * language cpp
 */

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        return (nums.size() + 1) * nums.size() / 2 - accumulate(nums.begin(), nums.end(), 0);
    }
};
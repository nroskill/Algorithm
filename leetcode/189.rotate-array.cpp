/**
 * https://leetcode.com/problems/rotate-array/
 * By Nroskill
 * runtime 19 ms
 * language cpp
 */

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
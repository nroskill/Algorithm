/**
 * https://leetcode.com/problems/product-of-array-except-self/
 * By Nroskill
 * runtime 69 ms
 * language cpp
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int begin = 1;
        int end = 1;
        vector<int> result(nums.size(), 1);
        for(int i = 0; i < nums.size(); i++) {
            result[i] *= begin;
            begin *= nums[i];
            result[nums.size() - i - 1] *= end;
            end *= nums[nums.size() - i - 1];
        }
        return result;
    }
};
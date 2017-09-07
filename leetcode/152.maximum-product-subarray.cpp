/**
 * https://leetcode.com/problems/maximum-product-subarray/
 * By Nroskill
 * runtime 3 ms
 * language cpp
 */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        int pos = result;
        int neg = result;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < 0)
                swap(pos, neg);
            pos = max(nums[i], pos * nums[i]);
            neg = min(nums[i], neg * nums[i]);
            result = max(result, pos);
        }
        return result;
    }
};
/**
 * https://leetcode.com/problems/minimum-size-subarray-sum/
 * By Nroskill
 * runtime 16 ms
 * language cpp
 */

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() < 1)
            return 0;
        int left = 0, right = 0;
        int result = 0x7fffffff;
        s -= nums[0];
        while(s > 0 && right + 1 < nums.size())
            s -= nums[++right];
        if(s > 0)
            return 0;
        result = right - left + 1;
        while(true) {
            while(s + nums[left] <= 0)
                s += nums[left++];
            result = min(result, right - left + 1);
            if(right + 1 >= nums.size())
                break;
            s -= nums[++right];
        }
        return result;
    }
};
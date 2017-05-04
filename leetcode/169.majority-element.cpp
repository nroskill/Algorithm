/**
 * https://leetcode.com/problems/majority-element/
 * By Nroskill
 * runtime 52 ms
 * language cpp
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums[0], count = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(count == 0)
                major = nums[i];
            if(nums[i] == major)
                count++;
            else
                count--;
            if(count >= nums.size() - i - 1)
                return major;
        }
        return major;
    }
};
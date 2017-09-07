/**
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 * By Nroskill
 * runtime 32 ms
 * language cpp
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i - 1]) count++;
            else nums[i - count] = nums[i];
        }
        nums.resize(nums.size() - count);
        return nums.size();
    }
};
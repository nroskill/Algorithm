/**
 * https://leetcode.com/problems/remove-element/
 * By Nroskill
 * runtime 6 ms
 * language cpp
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != val) nums[i - count] = nums[i];
            else count++;
        }
        nums.resize(nums.size() - count);
        return nums.size();
    }
};
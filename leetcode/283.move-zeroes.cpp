/**
 * https://leetcode.com/problems/move-zeroes/
 * By Nroskill
 * runtime 26 ms
 * language cpp
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i, j;
        for(i = 0, j = 0; i < nums.size(); i++)
            if(nums[i] != 0)
                nums[j++] = nums[i];
        while(j < nums.size())
            nums[j++] = 0;
    }
};
/**
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
 * By Nroskill
 * runtime 16 ms
 * language cpp
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 3)
            return nums.size();
        int current = 2;
        for(int i = 2; i < nums.size(); i++)
            if(nums[i] != nums[current - 2])
                nums[current++] = nums[i];
        return current;
    }
};
/**
 * https://leetcode.com/problems/search-insert-position/
 * By Nroskill
 * runtime 16 ms
 * language cpp
 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        while(start <= end) {
            if(nums[(start + end) / 2] == target)
                return (start + end) / 2;
            else if(nums[(start + end) / 2] > target)
                end = (start + end) / 2 - 1;
            else
                start = (start + end) / 2 + 1;
        }
        return start;
    }
};
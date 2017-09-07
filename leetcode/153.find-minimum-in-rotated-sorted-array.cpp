/**
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 * By Nroskill
 * runtime 3 ms
 * language cpp
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while(left < right) {
            mid = (left + right) / 2;
            if(nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left];
    }
};
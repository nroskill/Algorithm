/**
 * https://leetcode.com/problems/find-peak-element/
 * By Nroskill
 * runtime 3 ms
 * language cpp
 */

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int begin = 0;
        int end = nums.size() - 1;
        int mid;
        while(begin < end) {
            mid = (begin + end) / 2;
            if(nums[mid] < nums[mid + 1])
                begin = mid + 1;
            else
                end = mid;
        }
        return begin;
    }
};
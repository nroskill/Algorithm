/**
 * https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
 * By Nroskill
 * runtime 9 ms
 * language cpp
 */

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() < 1)
            return false;
        int low = 0, high = nums.size() - 1;
        while(low < high) {
            int mid = (low + high) / 2;
            if(nums[mid] == target)
                return true;
            else if(nums[mid] > nums[high]) {
                if(nums[mid] > target && nums[low] <= target)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else if(nums[mid] < nums[high]) {
                if(nums[mid] < target && nums[high] >= target)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            else
                high--;
        }
        return nums[low] == target;
    }
};
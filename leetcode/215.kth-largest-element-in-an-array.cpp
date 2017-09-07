/**
 * https://leetcode.com/problems/kth-largest-element-in-an-array/
 * By Nroskill
 * runtime 19 ms
 * language cpp
 */

class Solution {
public:
    void qsort(vector<int>& nums, int begin, int end, int target) {
        int low = begin;
        int high = end;
        int t = nums[low];
        while(low < high) {
            while(low < high && t >= nums[high])
                high--;
            nums[low] = nums[high];
            while(low < high && nums[low] >= t)
                low++;
            nums[high] = nums[low];
        }
        nums[low] = t;
        if(low == target - 1)
            return;
        else if(low > target - 1)
            qsort(nums, begin, low - 1, target);
        else
            qsort(nums, low + 1, end, target);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        qsort(nums, 0, nums.size() - 1, k);
        return nums[k - 1];
    }
};
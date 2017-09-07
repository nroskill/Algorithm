/**
 * https://leetcode.com/problems/search-in-rotated-sorted-array/
 * By Nroskill
 * runtime 9 ms
 * language cpp
 */

class Solution {
public:
	int find(vector<int>& nums, int target, int start, int end) {
        while(start <= end) {
            int mid = (end - start) / 2 + start;
            if(nums[mid] > target)
                end = mid - 1;
            else if(nums[mid] < target)
                start = mid + 1;
            else
                return mid;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        if(nums.size() == 1)
            return nums[0] == target ? 0 : -1;
        
        int offset = nums.size() / 2;
        int ret = -1;
        if(nums[0] < nums[nums.size() - 1]) 
            offset = 0;
        else {
            int left = 0;
            int right = nums.size() - 1;
            while(left <= right) {
                offset = (left + right + 1) / 2;
                if(nums[offset] == target)
                    return offset;
                if(nums[offset] < nums[offset - 1])
                    break;
                if(nums[offset] > nums[0])
                    left = offset + 1;
                else
                    right = offset - 1;
            }
            if(nums[offset - 1] >= target && nums[0] <= target)
                ret = find(nums, target, 0, offset - 1);
        }
        cout<<offset<<endl;
        if(ret == -1 && nums[offset] <= target && nums[nums.size() - 1] >= target)
            ret = find(nums, target, offset, nums.size() - 1);
        return ret;
    }
};
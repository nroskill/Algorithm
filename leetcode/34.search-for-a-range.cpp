/**
 * https://leetcode.com/problems/search-for-a-range/
 * By Nroskill
 * runtime 9 ms
 * language cpp
 */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() < 1 || target < nums[0] || target > nums[nums.size() - 1])
            return vector<int>({-1, -1});
        int left = 0;
        int right = nums.size() - 1;
        int mid = (left + right) / 2;
        while(left < right && nums[mid] != target) {
            if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
            mid = (left + right) / 2;
            
        }
        if(nums[mid] != target)
            return vector<int>({-1, -1});
        int front = mid;
        while(front >= 0 && nums[--front] == target);
        int back = mid;
        while(back < nums.size() && nums[++back] == target);
        return vector<int>({front + 1, back - 1});
    }
};
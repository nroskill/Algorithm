/**
 * https://leetcode.com/problems/next-permutation/
 * By Nroskill
 * runtime 12 ms
 * language cpp
 */

class Solution {
public:
    int findMin(vector<int>& nums, int start, int h) {
    	if(nums[nums.size() - 1] > h)
    		return nums.size() - 1;
        int mid = (start + nums.size()) / 2;
		while(mid > start && mid < nums.size())
        	if(nums[mid] > h)
        		mid = (mid + nums.size()) / 2;
        	else if(nums[mid - 1] <= h)
        		mid = (start + mid - 1) / 2;
        	else
        		return mid - 1;
        return start;
    }
    
    void nextPermutation(vector<int>& nums) {
        if(nums.size() < 2)
            return;
        int i = 0;
        for(i = nums.size() - 2; i >= 0; i--) {
        	if(nums[i] < nums[i + 1]) {
                swap(nums[findMin(nums, i + 1, nums[i])], nums[i]);
                break;
            }
        }
        sort(nums.begin() + 1 + i, nums.end());
    }
};
/**
 * https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
 * By Nroskill
 * runtime 138 ms
 * language cpp
 */

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        for(int i = 0; i < nums.size(); i++) {
            int val = abs(nums[i]) - 1;
            nums[val] = 0 - abs(nums[val]);
        }
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] > 0)
                result.push_back(i + 1);
        return result;
    }
};
/**
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
 * By Nroskill
 * runtime 82 ms
 * language cpp
 */

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min = 0x7fffffff, result = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < min)
                min = nums[i];
            result += nums[i];
        }
        return result - nums.size() * min;
    }
};
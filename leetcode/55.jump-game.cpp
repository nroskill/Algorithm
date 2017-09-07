/**
 * https://leetcode.com/problems/jump-game/
 * By Nroskill
 * runtime 12 ms
 * language cpp
 */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int pos = 0;
        for(int i = 0; i <= pos; i++) {
            pos = max(pos, nums[i] + i);
            if(pos >= nums.size() - 1)
                return true;
        }
        return false;
    }
};
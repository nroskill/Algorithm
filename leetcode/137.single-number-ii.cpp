/**
 * https://leetcode.com/problems/single-number-ii/
 * By Nroskill
 * runtime 9 ms
 * language cpp
 */

class Solution {
public:
    
    //reference: http://www.cnblogs.com/yangrouchuan/p/5323327.html
    int singleNumber(vector<int>& nums) {
        int one = 0;
        int two = 0;
        for(int i = 0; i < nums.size(); i++) {
            one = ~two & (one ^ nums[i]);
            two = ~one & (two ^ nums[i]);
        }
        return one;
    }
};
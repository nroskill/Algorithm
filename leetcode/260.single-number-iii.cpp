/**
 * https://leetcode.com/problems/single-number-iii/
 * By Nroskill
 * runtime 16 ms
 * language cpp
 */

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int r = 0;
        for(auto num : nums)
            r ^= num;
        int h = 0x00000001;
        while((h & r) == 0)
            h <<= 1;
        int r1 = 0, r2 = 0;
        for(auto num : nums) {
            if(num & h)
                r1 ^= num;
            else
                r2 ^= num;
        }
        return vector<int>({r1, r2});
    }
};
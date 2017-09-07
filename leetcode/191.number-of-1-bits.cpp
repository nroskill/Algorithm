/**
 * https://leetcode.com/problems/number-of-1-bits/
 * By Nroskill
 * runtime 6 ms
 * language cpp
 */

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        for(int i = 0; i < 32; i++) {
            result += 0x1 & n;
            n >>= 1;
        }
        return result;
    }
};
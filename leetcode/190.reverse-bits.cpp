/**
 * https://leetcode.com/problems/reverse-bits/
 * By Nroskill
 * runtime 6 ms
 * language cpp
 */

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(uint32_t i = 0, j = 0x0000001, k = 0x80000000; i < 16; i++) {
			result |= (k >> i) & (n << (31 - i * 2));
			result |= (j << i) & (n >> (31 - i * 2));
        }
        return result;
    }
};
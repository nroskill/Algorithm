/**
 * https://leetcode.com/problems/bitwise-and-of-numbers-range/
 * By Nroskill
 * runtime 38 ms
 * language cpp
 */

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int result = 0;
        for(int i = 0x40000000; i > 0; i >>= 1)
            if(i <= n - result) {
                if(i <= m - result)
                    result += i;
                else
                    break;
            }
        return result;
    }
};
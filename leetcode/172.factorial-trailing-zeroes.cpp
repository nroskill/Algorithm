/**
 * https://leetcode.com/problems/factorial-trailing-zeroes/
 * By Nroskill
 * runtime 3 ms
 * language cpp
 */

class Solution {
public:
    int trailingZeroes(int n) {
        int r = 0;
        for(long long int i = 5; i <= n; i *= 5)
            r += n / i;
        return r;
    }
};
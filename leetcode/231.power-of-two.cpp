/**
 * https://leetcode.com/problems/power-of-two/
 * By Nroskill
 * runtime 3 ms
 * language cpp
 */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && 2147483648 % n == 0;
    }
};
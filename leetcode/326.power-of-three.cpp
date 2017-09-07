/**
 * https://leetcode.com/problems/power-of-three/
 * By Nroskill
 * runtime 65 ms
 * language cpp
 */

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};
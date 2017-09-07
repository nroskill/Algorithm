/**
 * https://leetcode.com/problems/hamming-distance/
 * By Nroskill
 * runtime 6 ms
 * language cpp
 */

class Solution {
public:
    int hammingDistance(int x, int y) {
        int result = 0;
        while( x > 0 || y > 0) {
            result += x % 2 == y % 2 ? 0 : 1;
            x /= 2;
            y /= 2;
        }
        return result;
    }
};
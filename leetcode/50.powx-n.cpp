/**
 * https://leetcode.com/problems/powx-n/
 * By Nroskill
 * runtime 12 ms
 * language cpp
 */

class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0)
            return 0;
        if(n == 0)
            return 1;
        double t = myPow(x, n / 2);
        if(n % 2 == 0)
            return t * t;
        return t * t * (n > 0 ? x : 1 / x);
    }
};
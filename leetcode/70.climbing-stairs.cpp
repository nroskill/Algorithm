/**
 * https://leetcode.com/problems/climbing-stairs/
 * By Nroskill
 * runtime 0 ms
 * language cpp
 */

class Solution {
public:
    int climbStairs(int n) {
        if(n < 0)
            return 0;
        if(n < 2)
            return 1;
        int a = 1;
        int b = 1;
        int t = 0;
        for(int i = 2; i <=n; i++) {
            t = a + b;
            a = b;
            b = t;
        }
        return t;
    }
};
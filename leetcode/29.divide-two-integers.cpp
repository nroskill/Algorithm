/**
 * https://leetcode.com/problems/divide-two-integers/
 * By Nroskill
 * runtime 12 ms
 * language cpp
 */

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long int son = dividend;
        long long int dad = divisor;
        if(son / dad > numeric_limits<int>::max() ||  son / dad < numeric_limits<int>::min())
            return numeric_limits<int>::max();
        return dividend / divisor;
    }
};
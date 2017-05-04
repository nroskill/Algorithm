/**
 * https://leetcode.com/problems/number-complement/
 * By Nroskill
 * runtime 3 ms
 * language cpp
 */

class Solution {
public:
    int findComplement(int num) {
        if(num == 1)
            return 0;
        long long int p = 2;
        while(num >= p)
            p = p << 1;
        return p - num - 1;
    }
};
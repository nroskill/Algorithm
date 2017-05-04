/**
 * https://leetcode.com/problems/reverse-integer/
 * By Nroskill
 * runtime 15 ms
 * language cpp
 */

class Solution {
public:
    int reverse(int x) {
        if(!x)
            return 0;
        int flag = x / abs(x);
        long long int y = 0;
        x = abs(x);
        while(x > 0){
            y *= 10;
            y += x % 10;
            x /= 10;
        }
        if(y > 0x7fffffff)
            return 0;
        return flag * y;
    }
};
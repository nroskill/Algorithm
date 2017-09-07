/**
 * https://leetcode.com/problems/perfect-number/
 * By Nroskill
 * runtime 3 ms
 * language cpp
 */

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int s = sqrt(num);
        if(num == 1)
            return false;
        int sum = 1;
        for(int i = 2; i <= s; i++)
            if(num % i == 0)
                sum += (i + num / i);
        return num == sum;
    }
};
/**
 * https://leetcode.com/problems/count-primes/
 * By Nroskill
 * runtime 26 ms
 * language cpp
 */

class Solution {
public:
    int countPrimes(int n) {
        if(n < 1)
            return 0;
        bool save[n];
        int result = 0;
        memset(save, 0, sizeof(save));
        for(int i = 2; i < n; i++)
            if(!save[i]) {
                result++;
                for(int j = i << 1; j < n; j += i)
                    save[j] = true;
            }
        return result;
    }
};
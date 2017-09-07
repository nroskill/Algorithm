/**
 * https://leetcode.com/problems/permutation-sequence/
 * By Nroskill
 * runtime 6 ms
 * language cpp
 */

class Solution {
public:
    string getPermutation(int n, int k) {
        string result = string("123456789").substr(0, n);
        int m = 1;
        for(int i = 2; i < n; i++)
            m *= i;
        k -= 1;
        for(int i = 0; i < n - 1 && k; m /= (n - 1 - i++)) {
            if(k < m)
                continue;
            int t = result[i];
            int j;
            result[i] = result[i + k / m];
            for(j = i + k / m; j > i; j--)
                result[j] = result[j - 1];
            result[j + 1] = t;
            k %= m;
        }
        return result;
    }
};
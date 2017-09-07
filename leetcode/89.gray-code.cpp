/**
 * https://leetcode.com/problems/gray-code/
 * By Nroskill
 * runtime 6 ms
 * language cpp
 */

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result(1<<n, 0);
        for(int i = 0, j = 1; i < n; i++)
            for(int k = j - 1; k >= 0; k--)
                result[j++] = result[k] | (1<<i);
        return result;
    }
};
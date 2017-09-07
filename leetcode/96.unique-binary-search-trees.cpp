/**
 * https://leetcode.com/problems/unique-binary-search-trees/
 * By Nroskill
 * runtime 3 ms
 * language cpp
 */

class Solution {
public:
    int numTrees(int n) {
        vector<int> sum(n + 1, 0);
        sum[0] = sum[1] = 1;
        for(int i = 2; i <= n; i++)
            for(int j = 1; j <= i; j++)
                sum[i] += sum[j - 1] * sum[i - j];
        return sum[n];
    }
};
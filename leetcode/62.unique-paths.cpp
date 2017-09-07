/**
 * https://leetcode.com/problems/unique-paths/
 * By Nroskill
 * runtime 0 ms
 * language cpp
 */

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m < n)
            return uniquePaths(n, m);
        vector<int> cal(n, 1);
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                cal[j] += cal[j - 1];
        return cal[n - 1];
    }
};
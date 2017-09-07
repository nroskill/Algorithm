/**
 * https://leetcode.com/problems/friend-circles/
 * By Nroskill
 * runtime 29 ms
 * language cpp
 */

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        queue<int> pool;
        int result = 0;
        if(M.size() < 1)
            return 0;
        for(int i = 0; i < M.size(); i++) {
            if(M[i][i] == 0)
                continue;
            pool.push(i);
            result++;
            while(!pool.empty()) {
                int t = pool.front();
                pool.pop();
                M[t][t] = 0;
                for(int j = 0; j < M.size(); j++) {
                    if(M[t][j] || M[j][t]) {
                        pool.push(j);
                        M[t][j] = 0;
                        M[j][t] = 0;
                    }
                }
            }
        }
        return result;
    }
};
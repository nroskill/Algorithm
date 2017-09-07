/**
 * https://leetcode.com/problems/combination-sum-iii/
 * By Nroskill
 * runtime 0 ms
 * language cpp
 */

class Solution {
private:
    void helper(vector<vector<int>>& result, vector<int>& temp, int start, int k, int n) { 
        if((2 * start + k - 1) * k / 2 > n || (2 * start - k + 17) * k / 2 < n)
            return;
        if(k == 0 && n == 0) {
            result.push_back(temp);
            return;
        }
        
        for(int i = start; i < 10; i++) {
            temp[temp.size() - k] = i;
            helper(result, temp, i + 1, k - 1, n - i);
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> temp(k, 0);
        helper(result, temp, 1, k, n);
        return result;
    }
};
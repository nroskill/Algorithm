/**
 * https://leetcode.com/problems/combinations/
 * By Nroskill
 * runtime 136 ms
 * language cpp
 */

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        if(k == 0) {
            result.push_back(vector<int>());
            return result;
        }
        auto in = combine(n - 1, k - 1);
        for_each(in.begin(), in.end(), [n](vector<int>& t){ t.push_back(n);});
        result.insert(result.end(), in.begin(), in.end());
        if(n > k) {
            auto notin = combine(n - 1, k);
            result.insert(result.end(), notin.begin(), notin.end());
        }
        return result;
    }
};
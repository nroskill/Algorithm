/**
 * https://leetcode.com/problems/subsets-ii/
 * By Nroskill
 * runtime 6 ms
 * language cpp
 */

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> save;
        vector<vector<int>> result({vector<int>()});
        for_each(nums.begin(), nums.end(), [&save](int num){save[num]++;});
        for(auto& t : save) {
            vector<vector<int>> bak(result);
            int c = result.size();
            for(int i = 1; i <= t.second; i++) {
                result.insert(result.end(), bak.begin(), bak.end());
                for(int j = 0; j < c; j++)
                    result[i * c + j].insert(result[i * c + j].begin(), i, t.first);
            }
        }
        return result;
    }
};
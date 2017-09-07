/**
 * https://leetcode.com/problems/combination-sum/
 * By Nroskill
 * runtime 15 ms
 * language cpp
 */

class Solution {
public:
    vector<vector<int>> cal(vector<int>& candidates, int index, int target) {
        vector<vector<int>> result;
        if(index >= candidates.size())
            return result;
        for(int i = target / candidates[index]; i >=0; i--) {
            if(target - i * candidates[index] == 0) {
                result.push_back(vector<int>(i, candidates[index]));
                continue;
            }
            auto temp = cal(candidates, index + 1, target - i * candidates[index]);
            if(temp.size() > 0) {
                for(int j = 0; j < temp.size(); j++) {
                    vector<int> t(i, candidates[index]);
                    t.insert(t.end(), temp[j].begin(), temp[j].end());
                    result.push_back(t);
                }
            }
        }
        return result;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end(), [](int a, int b){return a > b;});
        result = cal(candidates, 0, target);
        return result;
    }
};
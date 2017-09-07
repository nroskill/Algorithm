/**
 * https://leetcode.com/problems/combination-sum-ii/
 * By Nroskill
 * runtime 16 ms
 * language cpp
 */

class Solution {
public:
    vector<vector<int>> cal(vector<int>& candidates, int index, int target) {
        vector<vector<int>> result;
        if(target == 0) {
            result.push_back(vector<int>());
            return result;
        }
        if(index >= candidates.size())
            return result;
        
        if(candidates[index] <= target) {
            auto temp = cal(candidates, index + 1, target - candidates[index]);
            for_each(temp.begin(), temp.end(), [&candidates, index](vector<int>& t) {
                t.push_back(candidates[index]);
            });
            result.insert(result.end(), temp.begin(), temp.end());
        }
        
        index = index + 1;
        while(index < candidates.size() && candidates[index] == candidates[index - 1]) index++;
        if(index < candidates.size()) {
            auto temp = cal(candidates, index, target);
            result.insert(result.end(), temp.begin(), temp.end());
        }
        
        return result;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end(), greater<int>());
        result = cal(candidates, 0, target);
        return result;
    }
};
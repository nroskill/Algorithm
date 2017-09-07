/**
 * https://leetcode.com/problems/group-anagrams/
 * By Nroskill
 * runtime 32 ms
 * language cpp
 */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, int> save;
        for_each(strs.begin(), strs.end(), [&](string& s) {
            string t(s);
            sort(t.begin(), t.end());
            if(save.find(t) != save.end()) {
                result[save[t]].push_back(s);
            }
            else {
                save[t] = result.size();
                result.push_back(vector<string>({s}));
            }
        });
        return result;
    }
};
/**
 * https://leetcode.com/problems/longest-common-prefix/
 * By Nroskill
 * runtime 9 ms
 * language cpp
 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0;
        if(!strs.size())
            return string("");
        for(i = 0; i < strs[0].length(); i++)
            for(int j = 1; j < strs.size(); j++)
                if(i >= strs[j].length() || strs[j][i] != strs[0][i])
                    return string(strs[0], 0, i);
        return strs[0];
    }
};
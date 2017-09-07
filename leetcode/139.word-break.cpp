/**
 * https://leetcode.com/problems/word-break/
 * By Nroskill
 * runtime 6 ms
 * language cpp
 */

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool cache[s.length() + 1];
        for(int i = 0; i <= s.length(); i++)
            cache[i] = false;
        cache[0] = true;
        for(int i = 0; i < s.length(); i++) {
            if(!cache[i])
                continue;
            for(int j = 0; j < wordDict.size(); j++)
                if(i + wordDict[j].length() <= s.length() && cache[i + wordDict[j].length()] == false && s.substr(i, wordDict[j].length()) == wordDict[j])
                    cache[i + wordDict[j].length()] = true;
        }
        return cache[s.length()];
    }
};
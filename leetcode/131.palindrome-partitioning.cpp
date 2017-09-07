/**
 * https://leetcode.com/problems/palindrome-partitioning/
 * By Nroskill
 * runtime 24 ms
 * language cpp
 */

class Solution {
public:
    vector<vector<string>> helper(bool* save, string& s, int index) {
        vector<vector<string>> result;
        for(int len = 1; index + len < s.length(); len++) {
            if(save[index * s.length() + index + len - 1]) {
                auto t = helper(save, s, index + len);
                if(t.size() == 0)
                    continue;
                auto sub = s.substr(index, len);
                for_each(t.begin(), t.end(), [&sub](vector<string>& c) {
                   c.push_back(sub); 
                });
                result.insert(result.end(), t.begin(), t.end());
            }
        }
        if(save[index * s.length() + s.length() - 1])
            result.push_back(vector<string>({s.substr(index, s.length() - index)}));
        return result;
    }
    
    vector<vector<string>> partition(string s) {
        if(s.length() == 0)
            return vector<vector<string>>();
        bool save[s.length()][s.length()];
        for(int i = 0; i < s.length(); i++)
            for(int j = 0; j < s.length(); j++)
                save[i][j] = false;
        for(int i = 0; i < s.length(); i++) {
            save[i][i] = true;
            for(int j = 1; i - j >= 0 && i + j < s.length(); j++)
                save[i - j][i + j] = save[i - j + 1][i + j - 1] && s[i - j] == s[i + j];
            if(i + 1 >= s.length())
                continue;
            save[i][i + 1] = s[i] == s[i + 1];
            for(int j = 1; i - j >= 0 && i + j + 1 < s.length(); j++)
                save[i - j][i + j + 1] = save[i - j + 1][i + j] && s[i - j] == s[i + j + 1];
        }
        auto r = helper((bool*)save, s, 0);
        for_each(r.begin(), r.end(), [](vector<string>& t) {
            reverse(t.begin(), t.end());
        });
        return r;
    }
};
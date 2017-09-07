/**
 * https://leetcode.com/problems/regular-expression-matching/
 * By Nroskill
 * runtime 199 ms
 * language cpp
 */

class Solution {
public:
    bool helper(string s, string p, int s_index, int p_index) {
        bool result = false;
        if(s_index == s.size() && p_index == p.size())
        	return true;
        if(p_index == p.size())
            return false;
        if(p_index + 1 < p.size() && p[p_index + 1] == '*') {
			result = result || helper(s, p, s_index, p_index + 2);
        	for(int i = s_index; i <= s.size() && (p[p_index] == '.' || p[p_index] == s[i]); i++)
                result = result || helper(s, p, i + 1, p_index + 2);
		}
        else if(p[p_index] == '.' || p[p_index] == s[s_index]) {
            result = helper(s, p, s_index + 1, p_index + 1);
        }
        return result;
    }

    bool isMatch(string s, string p) {
        return helper(s, p, 0, 0);
    }
};
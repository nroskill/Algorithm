/**
 * https://leetcode.com/problems/generate-parentheses/
 * By Nroskill
 * runtime 3 ms
 * language cpp
 */

class Solution {
public:
    void generate(vector<string>& result, string s, int left, int max) {
        if(s.length() == max * 2) {
            result.push_back(s);
            return;
        }
        if(left < max)
            generate(result, s + "(", left + 1, max);
        if(left > s.length() - left)
            generate(result, s + ")", left, max);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(result, "", 0, n);
        return result;
    }
};
/**
 * https://leetcode.com/problems/longest-valid-parentheses/
 * By Nroskill
 * runtime 6 ms
 * language cpp
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length() < 1)
            return 0;
        stack<int> save;
        save.push(0);
        for(int i = 1; i < s.length(); i++)
        	if(s[i] == '(' || (s[i] == ')' && (save.empty() || s[save.top()] == ')')))
        		save.push(i);
            else
                save.pop();
        if(save.empty())
            return s.length();
        
        int l = save.top();
        save.pop();
        int ret = s.length() - 1 - l;
        while(!save.empty()) { 
            int t = save.top();
            save.pop();
            ret = max(ret, l - t - 1);
            l = t;
        }
        
        return max(ret, l);
    }
};
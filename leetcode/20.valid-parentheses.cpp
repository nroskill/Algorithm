/**
 * https://leetcode.com/problems/valid-parentheses/
 * By Nroskill
 * runtime 3 ms
 * language cpp
 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        for(int i = 0; i < s.length(); i++)
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                t.push(s[i]);
            else if(t.empty() || (t.top() == '[' && s[i] != ']') || (t.top() == '(' && s[i] != ')') || (t.top() == '{' && s[i] != '}'))
                return false;
            else
                t.pop();
        return t.empty();
    }
};
/**
 * https://leetcode.com/problems/restore-ip-addresses/
 * By Nroskill
 * runtime 3 ms
 * language cpp
 */

class Solution {
public:
    bool valid(string& s, int start, int end) {
        int result = 0;
        if(start > end || (s[start] == '0' && start != end))
        	return false;
        for(int i = start; i <= end; i++) {
            result *= 10;
            result += (s[i] - '0');
            if(result > 255)
                return false;
        }
        return true;
    }
    
    void cal(vector<string>& result, int c, int index, string current, string& s) {
        if(c == 1 || index >= s.length()) {
            if(c == 1 && valid(s, index, s.length() - 1))
                result.push_back(current + s.substr(index, s.length() - index + 1));
            return;
        }
        if(s[index] == '0') {
            cal(result, c - 1, index + 1, current + "0.", s);
            return;
        }
        for(int i = index; i < s.length() && valid(s, index, i); i++)
            cal(result, c - 1, i + 1, current + s.substr(index, i - index + 1) + ".", s);
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string current;
        cal(result, 4, 0, current, s);
        return result;
    }
};
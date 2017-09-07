/**
 * https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/
 * By Nroskill
 * runtime 93 ms
 * language cpp
 */

class Solution {
public:
    bool better(string a, string b) {
        if(a.length() == 0)
            return false;
        if(a.length() != b.length())
            return a.length() > b.length();
        for(int i = 0; i < a.length(); i++)
            if(a[i] != b[i])
                return a[i] < b[i];
        return false;
    }

    bool judge(string a, string b) {
        int j = 0;
        for(int i = 0; i < a.length(); i++) {
            if(a[i] == b[j]) {
                j++;
                if(j == b.length())
                    break;
            }
        }
        return j == b.length();
    }

    string findLongestWord(string s, vector<string>& d) {
        string result = "";
        for(int i = 0; i < d.size(); i++)
            if(judge(s, d[i]) && !better(result, d[i]))
                result = d[i];
        return result;
    }
};
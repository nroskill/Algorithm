/**
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 * By Nroskill
 * runtime 3 ms
 * language cpp
 */

class Solution {
public:

    
    vector<string> letterCombinations(string digits) {
        if(digits.length() < 1)
            return vector<string>();
        queue<string> helper({""});
        vector<string> shit = vector<string>({
            " ",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        });
        for(int i = 0; i < digits.length(); i++) {
            while(helper.front().length() == i) {
                string t = helper.front();
                helper.pop();
                for(int j = 0; j < shit[digits[i] - '0'].length(); j++)
                    helper.push(t + shit[digits[i] - '0'][j]);
            }
        }
        vector<string> result(helper.size(), "");
        for(int i = 0; !helper.empty(); helper.pop())
            result[i++] = helper.front();
        return result;
    }
};
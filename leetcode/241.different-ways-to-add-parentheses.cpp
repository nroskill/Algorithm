/**
 * https://leetcode.com/problems/different-ways-to-add-parentheses/
 * By Nroskill
 * runtime 3 ms
 * language cpp
 */

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        for(int i = 0; i < input.length(); i++)
            if(input[i] == '+' || input[i] == '-' || input[i] == '*') {
                auto result1 = diffWaysToCompute(input.substr(0, i));
                auto result2 = diffWaysToCompute(input.substr(i + 1, input.length() - i - 1));
                for(auto r1 : result1)
                    for(auto r2 : result2)
                        result.push_back(input[i] == '+' ? r1 + r2 : input[i] == '-' ? r1 - r2 : r1 * r2);
            }
        if(result.size() == 0) {
            int j = 0;
            for(int i = 0; i < input.length(); i++)
                j = j * 10 + input[i] - '0';
            result.push_back(j);
        }
        return result;
    }
};
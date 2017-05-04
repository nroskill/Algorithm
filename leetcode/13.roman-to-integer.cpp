/**
 * https://leetcode.com/problems/roman-to-integer/
 * By Nroskill
 * runtime 95 ms
 * language cpp
 */

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> M = {
            {'I', 1},
            {'X', 10},
            {'C', 100},
            {'M', 1000},
            {'V', 5},
            {'L', 50},
            {'D', 500}
        };
        int result = M[s[s.length() - 1]];
        for(int i = s.length() - 2; i >= 0; i--)
            if(M[s[i]] < M[s[i + 1]])
                result -= M[s[i]];
            else
                result += M[s[i]];
        return result;
    }
};
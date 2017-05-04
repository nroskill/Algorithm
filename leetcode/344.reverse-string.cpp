/**
 * https://leetcode.com/problems/reverse-string/
 * By Nroskill
 * runtime 9 ms
 * language cpp
 */

class Solution {
public:
    string reverseString(string s) {
        std::reverse(s.begin(), s.end());
        return s;
    }
};
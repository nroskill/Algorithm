/**
 * https://leetcode.com/problems/find-the-difference/
 * By Nroskill
 * runtime 3 ms
 * language cpp
 */

class Solution {
public:
    char findTheDifference(string s, string t) {
        int result = 0, i;
        for(i = 0; i < s.length(); i++) {
            result -= s[i];
            result += t[i];
        }
        return result + t[i];
    }
};
/**
 * https://leetcode.com/problems/length-of-last-word/
 * By Nroskill
 * runtime 3 ms
 * language cpp
 */

class Solution {
public:
    int lengthOfLastWord(string s) {
        s = string(s, 0, s.find_last_not_of(' ') + 1);
        return s.length() - s.find_last_of(' ') - 1;
    }
};
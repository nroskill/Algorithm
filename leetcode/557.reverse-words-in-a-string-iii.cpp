/**
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/
 * By Nroskill
 * runtime 25 ms
 * language cpp
 */

class Solution {
public:
    string reverseWords(string s) {
        int index = s.find_first_not_of(" ", 0);
        int next = s.find_first_of(" ", index + 1);
        while(true) {
            if(string::npos == index)
                return s;
            if(string::npos == next) {
                reverse(s.begin() + index, s.end());
                return s;
            }
            reverse(s.begin() + index, s.begin() + next);
            index = s.find_first_not_of(" ", next + 1);
            next = s.find_first_of(" ", index + 1);
        }
        return s;
    }
};
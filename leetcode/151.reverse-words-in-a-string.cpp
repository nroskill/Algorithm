/**
 * https://leetcode.com/problems/reverse-words-in-a-string/
 * By Nroskill
 * runtime 6 ms
 * language cpp
 */

class Solution {
public:
    void reverseWords(string &s) {
        int begin = s.find_first_not_of(' ');
        int end = s.find_last_not_of(' ');
        if(begin == string::npos || end == string::npos) {
            s = "";
            return;
        }
        s = s.substr(begin, end - begin + 1);
        reverse(s.begin(), s.end());
        bool flag = false;
        int start = 0;
        for(int i = 0; i < s.length(); i++) {
            if(!flag && s[i] != ' ') {
                start = i;
                flag = true;
            }
            else if(flag && s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                flag = false;
            }
        }
        reverse(s.begin() + start, s.end());
        flag = false;
        int t = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ' && !flag) {
                s[t++] = s[i];
                flag = true;
            }
            else if(s[i] != ' ') {
                s[t++] = s[i];
                flag = false;
            }
        }
        s = s.substr(0, t);
    }
};
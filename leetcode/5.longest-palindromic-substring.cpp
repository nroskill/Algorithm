/**
 * https://leetcode.com/problems/longest-palindromic-substring/
 * By Nroskill
 * runtime 29 ms
 * language cpp
 */

class Solution {
public:
    int cal(string s, int i, int j) {
        while(i >= 0 && j < s.length())
            if(s[--i] != s[++j])
                break;
        return j - i - 1;
    }

    string longestPalindrome(string s) {
        int longestStart = 0;
        int longestLength = s.length() == 0 ? 0 : 1;
        int currentStart = 0;
        int currentLength = 0;
        for(int i = 0; i + 1 < s.length(); i++)
            if(s[i] == s[i + 1]) {
                currentLength = cal(s, i, i + 1);
                if(currentLength >= longestLength) {
                    longestLength = currentLength;
                    longestStart = i - currentLength / 2 + 1;
                }
            }
        for(int i = 0; i + 2 < s.length(); i++)
            if(s[i] == s[i + 2]) {
                currentLength = cal(s, i, i + 2);
                if(currentLength >= longestLength) {
                    longestLength = currentLength;
                    longestStart = i - currentLength / 2 + 1;
                }
            }
        return string(s, longestStart, longestLength);
    }
};
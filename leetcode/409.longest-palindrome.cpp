/**
 * https://leetcode.com/problems/longest-palindrome/
 * By Nroskill
 * runtime 3 ms
 * language cpp
 */

class Solution {
public:
    int longestPalindrome(string s) {
        int count[52], result = 0;
        memset(count, 0, sizeof(count));
        for(int i = 0; i < s.length(); i++)
            if(s[i] <= 'Z' && s[i] >= 'A')
                count[s[i] - 'A']++;
            else
                count[s[i] - 'a' + 26]++;
        for(int i = 0; i < 52; i++)
            result += count[i] % 2 == 0 ? count[i] : count[i] - 1;
        if(result < s.length())
            return result + 1;
        return result;
    }
};
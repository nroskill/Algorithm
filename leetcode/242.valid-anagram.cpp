/**
 * https://leetcode.com/problems/valid-anagram/
 * By Nroskill
 * runtime 9 ms
 * language cpp
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[26];
        if(s.length() != t.length())
            return false;
        memset(count, 0, sizeof(count));
        for(int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++)
            if(count[i])
                return false;
        return true;
    }
};
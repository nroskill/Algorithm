/**
 * https://leetcode.com/problems/ransom-note/
 * By Nroskill
 * runtime 33 ms
 * language cpp
 */

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[26] = { 0 };
        if(ransomNote.length() > magazine.length())
            return false;
        for(int i = 0; i < magazine.length(); i++)
            count[magazine[i] - 'a']++;
        for(int i = 0; i < ransomNote.length(); i++)
            if(--count[ransomNote[i] - 'a'] < 0)
                return false;
        return true;
    }
};
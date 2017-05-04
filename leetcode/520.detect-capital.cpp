/**
 * https://leetcode.com/problems/detect-capital/
 * By Nroskill
 * runtime 13 ms
 * language cpp
 */

class Solution {
public:
    bool isUppercaseLetter(char a) {
        return a <= 'Z' && a >= 'A';
    }
    
    bool detectCapitalUse(string word) {
        for(int i = 1; i < word.length(); i++)
            if(isUppercaseLetter(word[i - 1]) != isUppercaseLetter(word[i]) && !(i == 1 && isUppercaseLetter(word[i - 1])))
                return false;
        return true;
    }
};
/**
 * https://leetcode.com/problems/valid-palindrome/
 * By Nroskill
 * runtime 16 ms
 * language cpp
 */

class Solution {
public:
    bool judgeEqual(char a, char b) {
        if(judgeNumber(a) && judgeNumber(b))
            return a == b;
        else if(judgeLetter(a) && judgeLetter(b))
            return abs(a - b) == 32 || abs(a - b) == 0;
        return false;
    }
    
    bool judgeLetter(char a) {
        return (a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z');
    }
    
    bool judgeNumber(char a) {
        return a >= '0' && a <= '9';
    }
    
    bool isPalindrome(string s) {
        if(s.length() == 0)
            return true;
        for(int left = 0, right = s.length() - 1; left < right; left++, right--) {
            while(!judgeLetter(s[left]) && !judgeNumber(s[left]))
                left++;
            if(left >= right)
                break;
            while(!judgeLetter(s[right]) && !judgeNumber(s[right]))
                right--;
            if(left >= right)
                break;
            if(!judgeEqual(s[left], s[right]))
                return false;
        }
        return true;
    }
};
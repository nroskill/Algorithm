/**
 * https://leetcode.com/problems/reverse-string-ii/
 * By Nroskill
 * runtime 12 ms
 * language cpp
 */

class Solution {
public:
    void rever(string& s, int start, int end) {
        char temp;
        for(int i = 0; start + i <= (start + end) / 2; i++) {
            temp = s[start + i];
            s[start + i] = s[end - i];
            s[end - i] = temp;
        }
    }
    
    string reverseStr(string s, int k) {
        for(int i = 0; i < s.length(); i = 2 * k + i) {
            if(s.length() - i < k) {
                rever(s, i, s.length() - 1);
                break;
            }
            rever(s, i, i + k - 1);
        }
        return s;
    }
};
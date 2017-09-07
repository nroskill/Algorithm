/**
 * https://leetcode.com/problems/excel-sheet-column-number/
 * By Nroskill
 * runtime 6 ms
 * language cpp
 */

class Solution {
public:
    int titleToNumber(string s) {
        int sum = 1, result = 0;
        for(int i = s.length() - 1; i >= 0; i--) {
            result += sum * (s[i] - 'A' + 1);
            sum *= 26;
        }
        return result;
    }
};
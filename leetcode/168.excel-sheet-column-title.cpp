/**
 * https://leetcode.com/problems/excel-sheet-column-title/
 * By Nroskill
 * runtime 0 ms
 * language cpp
 */

class Solution {
public:
    string convertToTitle(int n) {
        string r;
        while(n > 0) {
            r = string(1, 'A' + (n - 1) % 26) + r;
            n = (n - 1) / 26;
        }
        return r;
    }
};
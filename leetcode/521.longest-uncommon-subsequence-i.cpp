/**
 * https://leetcode.com/problems/longest-uncommon-subsequence-i/
 * By Nroskill
 * runtime 3 ms
 * language cpp
 */

class Solution {
public:
    int findLUSlength(string a, string b) {
        return a == b ? -1 : max(a.length(), b.length());
    }
};
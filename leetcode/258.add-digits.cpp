/**
 * https://leetcode.com/problems/add-digits/
 * By Nroskill
 * runtime 9 ms
 * language cpp
 */

class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};
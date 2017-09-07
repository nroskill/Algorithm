/**
 * https://leetcode.com/problems/plus-one/
 * By Nroskill
 * runtime 6 ms
 * language cpp
 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i;
        for(i = digits.size() - 1; digits[i] == 9 && i >= 0; i--)
            digits[i] = 0;
        if(i >= 0)
            digits[i] += 1;
        else
            digits.insert(digits.begin(), 1);
        return digits;
    }
};
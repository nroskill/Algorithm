/**
 * https://leetcode.com/problems/sort-colors/
 * By Nroskill
 * runtime 3 ms
 * language cpp
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c[] = {0, 0, 0};
        for_each(nums.begin(), nums.end(), [&c](int& color){ c[color]++;});
        for(int offset = 0, i = 0; i <= 2; i++) {
            for_each(nums.begin() + offset, nums.begin() + offset + c[i], [i](int& color){color = i;});
            offset += c[i];
        }
    }
};
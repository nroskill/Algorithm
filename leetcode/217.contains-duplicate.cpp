/**
 * https://leetcode.com/problems/contains-duplicate/
 * By Nroskill
 * runtime 46 ms
 * language cpp
 */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return unordered_set<int>(nums.begin(), nums.end()).size() < nums.size();
    }
};
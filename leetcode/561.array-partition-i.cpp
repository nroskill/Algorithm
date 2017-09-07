/**
 * https://leetcode.com/problems/array-partition-i/
 * By Nroskill
 * runtime 75 ms
 * language cpp
 */

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int result = 0;
        bool flag = false;
        sort(nums.begin(), nums.end());
        for_each(nums.begin(), nums.end(), [&result, &flag](int t){
           result += (flag = !flag) ? t : 0; 
        });
        return result;
    }
};
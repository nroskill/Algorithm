/**
 * https://leetcode.com/problems/majority-element-ii/
 * By Nroskill
 * runtime 13 ms
 * language cpp
 */

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        int num1 = 0, num2 = 0;
        for(auto num : nums) {
            if(num == num1)
                count1++;
            else if(num == num2)
                count2++;
            else if(count1 == 0) {
                num1 = num;
                count1 = 1;
            }
            else if(count2 == 0) {
                num2 = num;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }
        count1 = count2 = 0;
        for(auto num: nums) {
            if(num == num1)
                count1++;
            else if(num == num2)
                count2++;
        }
        vector<int> result;
        if(count1 > nums.size() / 3)
            result.push_back(num1);
        if(count2 > nums.size() / 3)
            result.push_back(num2);
        return result;
    }
};
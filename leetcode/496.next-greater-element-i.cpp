/**
 * https://leetcode.com/problems/next-greater-element-i/
 * By Nroskill
 * runtime 16 ms
 * language cpp
 */

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> result;
        for(int i = 0; i < findNums.size(); i++) {
            int j, k;
            for(j = 0; j < nums.size(); j++)
                if(nums[j] == findNums[i])
                    break;
            k = nums[j++];
            while(j < nums.size()) {
                if(k < nums[j])
                    break;
                j++;
            }
            if(j == nums.size())
                result.push_back(-1);
            else
                result.push_back(nums[j]);
        }
        return result;
    }
};
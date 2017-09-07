/**
 * https://leetcode.com/problems/summary-ranges/
 * By Nroskill
 * runtime 0 ms
 * language cpp
 */

class Solution {
private:
    string helper(int a, int b) {
        if(a == b)
            return to_string(a);
        return to_string(a) + "->" + to_string(b);
    }
    
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0)
            return vector<string>();
        int start = nums[0];
        vector<string> result;
        for(int i = 1; i < nums.size(); i++)
            if(nums[i - 1] + 1 != nums[i]) {
                result.push_back(helper(start, nums[i - 1]));
                start = nums[i];
            }
        result.push_back(helper(start, nums[nums.size() - 1]));
        return result;
    }
};
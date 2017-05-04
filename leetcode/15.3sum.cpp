/**
 * https://leetcode.com/problems/3sum/
 * By Nroskill
 * runtime 109 ms
 * language cpp
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int i = 0; i < nums.size(); i++) {
            int j = i + 1, k = nums.size() - 1;
            while(j < k) {
                if(nums[j] + nums[k] < -nums[i])
                    j++;
                else if(nums[j] + nums[k] > -nums[i])
                    k--;
                else {
                    result.push_back(vector<int>({nums[i], nums[j], nums[k]}));
                    while(j < k && nums[j] == result[result.size() - 1][1]) j++;
                    while(j < k && nums[k] == result[result.size() - 1][2]) k--;
                }
            }
            while(i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
        }
        return result;
    }
};
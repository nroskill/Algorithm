/**
 * https://leetcode.com/problems/4sum/
 * By Nroskill
 * runtime 43 ms
 * language cpp
 */

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4)
            return vector<vector<int>>();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int i = 0; i < nums.size() - 3; i++) {
            for(int j = i + 1; j < nums.size() - 2; j++) {
                int tar = target - nums[i] - nums[j]; 
                int head = j + 1;
                int tail = nums.size() - 1;
                while(head < tail) {
                    int temp = nums[head] + nums[tail];
                    if(temp == tar)
                        result.push_back(vector<int>({nums[i], nums[j], nums[head], nums[tail]}));
                    if(temp <= tar) {
                        head++;
                    	while(head < tail && nums[head] == nums[head - 1])
                        	head++;
                    }
                    if(temp >= tar) {
                        tail--;
                    	while(head < tail && nums[tail] == nums[tail + 1])
                        	tail--;
					}
                }
                while(j + 1 < nums.size() - 2 && nums[j] == nums[j + 1])
                    j++;
            }
            while(i + 1 < nums.size() - 3 && nums[i] == nums[i + 1])
                i++;
        }
        return result;
    }
};
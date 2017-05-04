/**
 * https://leetcode.com/problems/3sum-closest/
 * By Nroskill
 * runtime 9 ms
 * language cpp
 */

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        if(nums.size() < 3)
            return accumulate(nums.begin(), nums.end(), 0);
        int best = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size(); i++) {
            int begin = i + 1;
            int end = nums.size() - 1;
            while(begin < end) {
                int cur = nums[i] + nums[begin] + nums[end];
                best = abs(target - best) > abs(target - cur) ? cur : best;
                if(best == target)
                    return target;    
                (cur > target) ? end-- : begin++;
            }
        }
        return best;
    }
};
/**
 * https://leetcode.com/problems/contiguous-array/
 * By Nroskill
 * runtime 126 ms
 * language cpp
 */

class Solution {
public:
    int valOf(int i) {
        if(i)
            return 1;
        else
            return -1;
    }

    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> pool;
        pool[0] = -1;
        int cur = 0;
        int result = 0;
        for(int i = 0; i < nums.size(); i++) {
            cur += valOf(nums[i]);
            auto t = pool.find(cur);
            if(t != pool.end()) {
                result = max(result, i - t->second);
            }
            else {
                pool[cur] = i;
            }
        }
        return result;
    }
};
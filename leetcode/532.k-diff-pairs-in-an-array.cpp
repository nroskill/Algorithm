/**
 * https://leetcode.com/problems/k-diff-pairs-in-an-array/
 * By Nroskill
 * runtime 36 ms
 * language cpp
 */

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0 || nums.size() == 0)
            return 0;
        int count = 0;
        map<int, int> s;
        for(int i = 0; i < nums.size(); i++)
            s[nums[i]]++;
        if(k == 0) {
            for(auto i = s.begin(); i != s.end(); i++)
                if((*i).second >= 2)
                    count++;
        }
        else {
            for(auto i = s.begin(); i != s.end(); i++)
                if(s.count((*i).first + k) != 0)
                    count++;

        }
        return count;
    }
};
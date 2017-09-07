/**
 * https://leetcode.com/problems/intersection-of-two-arrays-ii/
 * By Nroskill
 * runtime 9 ms
 * language cpp
 */

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> result;
        vector<int> res;
        for(int i = 0; i < nums1.size(); i++)
            if(result.count(nums1[i]) == 0)
                result[nums1[i]] = 1;
            else
                result[nums1[i]]++;
        for(int i = 0; i < nums2.size(); i++)
            if(result.count(nums2[i]) != 0 && result[nums2[i]] > 0) {
                res.push_back(nums2[i]);
                result[nums2[i]]--;
            }
        return res;
    }
};
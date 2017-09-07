/**
 * https://leetcode.com/problems/median-of-two-sorted-arrays/
 * By Nroskill
 * runtime 62 ms
 * language cpp
 */

class Solution {
public:
    vector<int> merge(vector<int>& nums1, vector<int>& nums2){
        int i = 0, j = 0;
        int m = nums1.size(), n = nums2.size();
        vector<int> result(m + n);
        while(i < m && j < n){
            if(nums1[i] < nums2[j])
                result[i + j] = nums1[i++];
            else
                result[i + j] = nums2[j++];
        }
        while(i < m)
            result[i + j] = nums1[i++];
        while(j < n)
            result[i + j] = nums2[j++];
        return result;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result = merge(nums1, nums2);
        if(result.size() % 2 == 0)
            return (result[result.size() / 2] + result[ result.size() / 2 - 1]) * 1.0 / 2;
        else
            return result[result.size() / 2];
    }
};
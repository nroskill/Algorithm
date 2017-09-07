/**
 * https://leetcode.com/problems/merge-sorted-array/
 * By Nroskill
 * runtime 6 ms
 * language cpp
 */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        while(i < m && j < n) {
            if(nums1[m - i - 1] > nums2[n - j - 1]) {
                nums1[m + n - i - j - 1] = nums1[m - i - 1];
                i++;
            }
            else {
                nums1[m + n - i - j - 1] = nums2[n - j - 1];
                j++;
            }
        }
        while(j < n) {
            nums1[n - j - 1] = nums2[n - j - 1];
            j++;
        }
    }
};
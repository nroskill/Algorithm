/**
 * https://leetcode.com/problems/container-with-most-water/
 * By Nroskill
 * runtime 22 ms
 * language cpp
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = min(height[0], height[height.size() - 1]) * (height.size() - 1), i = 0, j = height.size() - 1;
        while(i < j) {
            int h = min(height[i], height[j]);
            result = max(result, h * (j - i));
            while(height[i] <= h && i < j) i++;
            while(height[j] <= h && i < j) j--;
        }
        return result;
    }
};
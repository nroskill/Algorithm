/**
 * https://leetcode.com/problems/search-a-2d-matrix/
 * By Nroskill
 * runtime 13 ms
 * language cpp
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() < 1 || matrix[0].size() < 1)
            return false;
        int per = matrix[0].size();
        int begin = 0, end = matrix.size() * per - 1;
        int mid = 0;
        while(begin <= end) {
            mid = (begin + end) >> 1;
            if(matrix[mid / per][mid % per] == target)
                return true;
            else if(matrix[mid / per][mid % per] < target)
                begin = mid + 1;
            else
                end = mid - 1;
        }
        return false;
    }
};
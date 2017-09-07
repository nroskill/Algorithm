/**
 * https://leetcode.com/problems/pascals-triangle-ii/
 * By Nroskill
 * runtime 3 ms
 * language cpp
 */

class Solution {
public:
    int cal(int row, int column) {
        int j = 2;
        long long int result = 1;
        for(int i = row; i >= row - column + 1; i--) {
            result *= i;
            while(j <= column && result % j == 0)
                result /= j++;
        }
        return result;
    }
    
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1, 1);
        for(int i = 1; i < rowIndex; i++)
            result[i] = cal(rowIndex, i);
        return result;
    }
};
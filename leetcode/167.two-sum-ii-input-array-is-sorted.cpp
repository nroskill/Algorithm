/**
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
 * By Nroskill
 * runtime 6 ms
 * language cpp
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while(i < j) {
            if(numbers[i] + numbers[j] == target)
                break;
            else if(numbers[i] + numbers[j] > target)
                j--;
            else
                i++;
        }
        return vector<int>({i + 1, j + 1});
    }
};
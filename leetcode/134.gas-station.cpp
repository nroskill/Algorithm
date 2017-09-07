/**
 * https://leetcode.com/problems/gas-station/
 * By Nroskill
 * runtime 6 ms
 * language cpp
 */

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int total = 0;
        int current = 0;
        for(int i = 0; i < gas.size(); i++) {
            current += gas[i] - cost[i];
            if(current < 0) {
                start = i + 1;
                total += current;
                current = 0;
            }
        }
        if(current > 0)
            total += current;
        return total < 0 ? -1 : start;
    }
};
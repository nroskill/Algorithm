/**
 * https://leetcode.com/problems/zigzag-conversion/
 * By Nroskill
 * runtime 35 ms
 * language cpp
 */

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        vector<string> result;
        for(int i = 0; i < numRows; i++)
            result.push_back(string(""));
        for(int i = 0; i < s.length(); i++)
            if(i % (2 * (numRows - 1)) < numRows)
                result[i % (2 * (numRows - 1))] += s[i];
            else
                result[2 * numRows - 2 - i % (2 * (numRows - 1))] += s[i];
    
        for(int i = 1; i < result.size(); i++)
            result[0] += result[i];
        return result[0];
    }
};
/**
 * https://leetcode.com/problems/largest-number/
 * By Nroskill
 * runtime 3 ms
 * language cpp
 */

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> helper;
        for_each(nums.begin(), nums.end(), [&helper](int a) {
            helper.push_back(to_string(a));
        });
        sort(helper.begin(), helper.end(), [](string& a, string& b) {
            return a + b > b + a;
        });
        string result;
        int i;
        for(i = 0; i < helper.size(); i++)
            result += helper[i];
        for(i = 0; i < result.length() - 1; i++)
            if(result[i] != '0')
                break;
        return result.substr(i);
    }
};
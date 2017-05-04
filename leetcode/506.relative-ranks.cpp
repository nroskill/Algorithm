/**
 * https://leetcode.com/problems/relative-ranks/
 * By Nroskill
 * runtime 13 ms
 * language cpp
 */

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        priority_queue<pair<int,int> > pq;
        for(int i = 0; i < nums.size(); i++)
        {
            pq.push(make_pair(nums[i], i));
        }
        vector<string> result(nums.size(),"");
        int count = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(count==1) {result[pq.top().second] = "Gold Medal"; count++;}
            else if(count==2) {result[pq.top().second] = "Silver Medal"; count++;}
            else if(count==3) {result[pq.top().second] = "Bronze Medal"; count++;}
            else {result[pq.top().second] = to_string(count); count++;}
            pq.pop();
        }
        return result;
    }
};
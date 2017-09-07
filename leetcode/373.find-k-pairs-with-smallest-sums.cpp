/**
 * https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
 * By Nroskill
 * runtime 113 ms
 * language cpp
 */

class Solution
{
public:
    
    struct cmp
    {
        bool operator()(pair<int, int>& a, pair<int, int>& b)
        {
            return a.first + a.second < b.first + b.second;
        }
    };
    
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
    {
        vector<pair<int, int>> result;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        
        for(int i = 0; i < nums1.size(); i++)
            for(int j = 0; j < nums2.size(); j++)
            {
                if(pq.size() < k)
                {
                    pq.push(pair<int, int>(nums1[i], nums2[j]));
                }
                else if(nums1[i] + nums2[j] < pq.top().first + pq.top().second)
                {
                    pq.pop();
                    pq.push(pair<int, int>(nums1[i], nums2[j]));
                }
            }
            
        while(!pq.empty())
        {
            result.insert(result.begin(), pq.top());
            pq.pop();
        }
        
        return result;
    }
};
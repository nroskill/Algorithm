/**
 * https://leetcode.com/problems/course-schedule-ii/
 * By Nroskill
 * runtime 16 ms
 * language cpp
 */

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        int counter[numCourses];
        vector<unordered_set<int>> next(numCourses);
        queue<int> explore;
        vector<int> result;
        
        memset(counter, 0, sizeof(counter));
        for(auto i : prerequisites) {
            next[i.second].insert(i.first);
            counter[i.first]++;
        }
        
        for(int i = 0; i < numCourses; i++)
            if(counter[i] == 0)
                explore.push(i);
        
        while(!explore.empty()) {
            int t = explore.front();
            explore.pop();
            result.push_back(t);
            for(auto i : next[t])
                if(--counter[i] == 0)
                    explore.push(i);
        }
        
        return result.size() == numCourses ? result : vector<int>();
    }
};
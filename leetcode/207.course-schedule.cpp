/**
 * https://leetcode.com/problems/course-schedule/
 * By Nroskill
 * runtime 16 ms
 * language cpp
 */

class Solution {
private:
    bool canReach(vector<unordered_set<int>>& graph, bool cache[], bool reached[], int index) {
        if(cache[index])
            return true;
        if(reached[index])
            return false;
        reached[index] = true;
        for(auto i : graph[index])
            if(!canReach(graph, cache, reached, i)) {
                reached[index] = false;
                return false;
            }
        
        reached[index] = false;
        return cache[index] = true;
    }
    
public:
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses, unordered_set<int>());
        bool cache[numCourses];
        bool reached[numCourses];
        memset(cache, 0, sizeof(cache));
        memset(reached, 0, sizeof(reached));
        for(auto i : prerequisites)
            graph[i.first].insert(i.second);
        
        for(int i = 0; i < numCourses; i++)
            if(!cache[i] && !canReach(graph, cache, reached, i))
                return false;
        
        return true;
    }
};
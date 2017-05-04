/**
 * https://leetcode.com/problems/number-of-boomerangs/
 * By Nroskill
 * runtime 202 ms
 * language cpp
 */

class Solution {
public:
    int distance(pair<int, int> a, pair<int, int> b) {
        return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
    }
    
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        unordered_map<int, int> record;
        int result = 0;
        for(int i = 0; i < points.size(); i++) {
            record.clear();
            for(int j = 0; j < points.size(); j++) {
                if(i == j)
                    continue;
                int dis = distance(points[i], points[j]);
                result += record[dis] * 2;
                record[dis] += 1;
            }
        }
        return result;
    }
};
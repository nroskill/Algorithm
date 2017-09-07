/**
 * https://leetcode.com/problems/merge-intervals/
 * By Nroskill
 * runtime 9 ms
 * language cpp
 */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() <= 1)
            return intervals;
        
        vector<Interval> result;
        sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b) { return a.start < b.start;});
        int start = intervals[0].start;
        int end = intervals[0].end;
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i].start > end) {
                result.push_back(Interval(start, end));
                start = intervals[i].start;
            }
            end = max(end, intervals[i].end);
        }
        result.push_back(Interval(start, end));
        return result;
    }
};
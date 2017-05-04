/**
 * https://leetcode.com/problems/minimum-time-difference/
 * By Nroskill
 * runtime 16 ms
 * language cpp
 */

class Solution {
public:
    int timestamp(string time) {
        return ((time[0] - '0') * 10 + (time[1] - '0')) * 60 + (time[3] - '0') * 10 + (time[4] - '0');
    }
    
    int findMinDifference(vector<string>& timePoints) {
        bitset<2160> count;
        count.reset();
        for(int i = 0; i < timePoints.size(); i++) {
            int stamp = timestamp(timePoints[i]);
            if(count[stamp])
                return 0;
            else
                count[stamp] = 1;
            if(stamp < 720) {
                if(count[stamp + 1440])
                    return 0;
                else
                    count[stamp + 1440] = 1;
            }
        }
        int result = 0x7fffffff;
        for(int i = 0, j = -1; i < count.size(); i++)
            if(count[i]) {
                if(j >= 0)
                    result = min(result, i - j);
                j = i;
            }
        return result;
    }
};
/**
 * https://leetcode.com/problems/heaters/
 * By Nroskill
 * runtime 76 ms
 * language cpp
 */

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int j = 0;
        int result = -1;
        for(int i = 0; i < houses.size(); i++) {
            while(houses[i] >= heaters[j] && j + 1 < heaters.size() && houses[i] >= heaters[j + 1])
                j++;
            int t = abs(houses[i] - heaters[j]);
            if(j + 1 < heaters.size())
                t = min(t, abs(heaters[j + 1] - houses[i]));
            result = max(result, t);
        }
        return result;
    }
};
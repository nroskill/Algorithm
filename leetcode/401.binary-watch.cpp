/**
 * https://leetcode.com/problems/binary-watch/
 * By Nroskill
 * runtime 3 ms
 * language cpp
 */

class Solution {
public:
    string inttostring(int hour, int minute) {
        return to_string(hour) + (minute < 10 ? string(":0") : string(":")) + to_string(minute);
    }
    
    void cal(vector<int>& result, int num, int index, int time, int max, vector<int> helper) {
        if(time > max)
            return;
        if(num == 0) {
            result.push_back(time);
            return;
        }
        for(int i = index; i < helper.size() && helper.size() - i >= num; i++)
            cal(result, num - 1, i + 1, time + helper[i], max, helper);
    }
    
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        for(int i = 0; i <= num; i++) {
            vector<int> hour, minute;
            cal(hour, i, 0, 0, 11, vector<int>({1, 2, 4, 8}));
            cal(minute, num - i, 0, 0, 59, vector<int>({1, 2, 4, 8, 16, 32}));
            for(int j = 0; j < hour.size(); j++)
                for(int k = 0; k < minute.size(); k++)
                    result.push_back(inttostring(hour[j], minute[k]));
        }
            
        return result;
    }
};
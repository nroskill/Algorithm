/**
 * https://leetcode.com/problems/construct-the-rectangle/
 * By Nroskill
 * runtime 3 ms
 * language cpp
 */

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int W = sqrt(area);
        vector<int> result;
        while(W >= 1)
            if(area % W == 0) {
                result.push_back(area / W);
                result.push_back(W);
                break;
            }
            else
                W--;
        return result;
    }
};
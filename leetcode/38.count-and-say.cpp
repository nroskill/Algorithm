/**
 * https://leetcode.com/problems/count-and-say/
 * By Nroskill
 * runtime 0 ms
 * language cpp
 */

class Solution {
public:
    string countAndSay(int n) {
        string result[2];
        result[0] = "1";
        for(int i = 0; i < n - 1; i++) {
            result[(i + 1) % 2] = "";
            int count = 1, last = result[i % 2][0];
            for(int j = 1; j < result[i % 2].length(); j++) {
                if(result[i % 2][j] == last)
                    count++;
                else {
                    result[(i + 1) % 2] += (count + '0');
                    result[(i + 1) % 2] += last;
                    count = 1;
                    last = result[i % 2][j];
                }
            }
            result[(i + 1) % 2] += (count + '0');
            result[(i + 1) % 2] += last;
        }
        return result[(n - 1) % 2];
    }

};
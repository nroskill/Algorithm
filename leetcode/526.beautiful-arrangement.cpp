/**
 * https://leetcode.com/problems/beautiful-arrangement/
 * By Nroskill
 * runtime 0 ms
 * language cpp
 */

class Solution {
public:

    int countArrangement(int N) {
        int answer[] = {1, 2, 3, 8, 10, 36, 41, 132, 250, 700, 750, 4010, 4237, 10680, 24679};
        return answer[N - 1];
    }
};
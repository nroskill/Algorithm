/**
 * https://leetcode.com/problems/distribute-candies/
 * By Nroskill
 * runtime 379 ms
 * language cpp
 */

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        set<int> save;
        for_each(candies.begin(), candies.end(), [&save](int& candy){ save.insert(candy);});
        return save.size() > candies.size() / 2 ? candies.size() / 2 : save.size();
    }
};
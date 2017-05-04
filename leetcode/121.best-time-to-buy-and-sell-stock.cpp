/**
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * By Nroskill
 * runtime 6 ms
 * language cpp
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int minPrice = prices[0], profit = 0;
        for(int i = 1; i < prices.size(); i++) {
            profit = max(profit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return profit;
    }
};
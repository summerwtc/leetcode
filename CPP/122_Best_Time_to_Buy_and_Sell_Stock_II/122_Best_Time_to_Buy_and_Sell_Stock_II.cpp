/**
Website: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

    122. Best Time to Buy and Sell Stock II
    
    Say you have an array for which the ith element is the price of a given stock on day i.
    
    Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and 
    sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time 
    (ie, you must sell the stock before you buy again).
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int size = prices.size();
        int maxBenefit = 0;
    
        for (int i = 1; i < size; ++i) {
            //if stock price at ith day is higher than that at (i-1)th day, sale the stock. 
            if ((prices[i] - prices[i - 1]) > 0) {
                maxBenefit += prices[i] - prices[i - 1];
            }
        }
        return maxBenefit;
    }
};

/**
Website: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

    121. Best Time to Buy and Sell Stock

    Say you have an array for which the ith element is the price of a given stock on day i.

    If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

    Example 1:

    Input: [7, 1, 5, 3, 6, 4]
    Output: 5

    max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)

    Example 2:

    Input: [7, 6, 4, 3, 1]
    Output: 0

    In this case, no transaction is done, i.e. max profit = 0.
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int max = 0; //max profit
        int lowestPrice = prices[0];
        int size = prices.size();
    
        //if saling stock at the ith day, find the lowest price before ith day
        for (int i = 1; i < size; ++i) {    
            if (prices[i] < lowestPrice) {
                //update the lowestPrice before the ith day
                lowestPrice = prices[i];
                continue;
            } else {
                //update max
                if (prices[i] - lowestPrice > max) {
                    max = prices[i] - lowestPrice;
                }
            }
        }
        return max;
    }
};

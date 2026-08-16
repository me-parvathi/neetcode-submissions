class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if (prices.size() < 2)
            return 0;

        int profit = 0;
        int max_profit = 0;

        int buy = 0;
        int sell = 1;

        while (sell < prices.size()) {

            // Today's price is cheaper than our current buy.
            // So today becomes the new buying day.
            if (prices[sell] < prices[buy]) {
                buy = sell;
            }
            else {
                profit = prices[sell] - prices[buy];
                max_profit = max(max_profit, profit);
            }

            // Sell always moves forward.
            sell++;
        }

        return max_profit;
    }
};
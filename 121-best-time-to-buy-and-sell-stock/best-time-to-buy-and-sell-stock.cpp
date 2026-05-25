class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = prices[0], max_profit = 0;

        for (int i = 0; i < n; i++){
            int profit = prices[i] - buy;
            if (profit > max_profit){
                max_profit = profit;
            }
            if (prices[i] < buy){
                buy = prices[i];
            }
        }

        return max_profit;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Benefit at each point
        int buy1 = INT_MIN;
        int sell1 = 0;
        int buy2 = INT_MIN;
        int sell2 = 0;

        for (int a : prices) {
            buy1 = max(buy1, -a);
            sell1 = max(sell1, buy1 + a);
            buy2 = max(buy2, sell1 - a);
            sell2 = max(sell2, buy2 + a);
        }
        return sell2;
    }
};
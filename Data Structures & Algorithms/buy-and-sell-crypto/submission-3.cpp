class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int buy = prices[0];
        for (auto p : prices) {
            maxP = max(maxP, p - buy);
            buy = min(buy, p);
        }
        return maxP;
    }
};

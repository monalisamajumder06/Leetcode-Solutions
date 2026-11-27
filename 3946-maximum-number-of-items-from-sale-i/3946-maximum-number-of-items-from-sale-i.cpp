class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> dp(budget + 1, 0);

        int cheapest = INT_MAX;

        for (auto &item : items) {
            cheapest = min(cheapest, item[1]);
        }

        for (int i = 0; i < n; i++) {
            int factor = items[i][0];
            int price = items[i][1];

            // Number of items obtained from the first purchase
            int count = 0;

            for (int j = 0; j < n; j++) {
                if (items[j][0] % factor == 0) {
                    count++;
                }
            }

            // 0/1 Knapsack: first purchase of this item
            for (int j = budget; j >= price; j--) {
                dp[j] = max(dp[j],
                            dp[j - price] + count);
            }
        }

        int ans = 0;

        // Use remaining budget to buy cheapest items
        for (int j = 0; j <= budget; j++) {
            ans = max(ans, dp[j] + (budget - j) / cheapest);
        }

        return ans;
    }
};
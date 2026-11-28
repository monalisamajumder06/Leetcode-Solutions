class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        // Count items having each factor
        vector<int> freq(n + 1, 0);

        int minPrice = INT_MAX;

        for (auto& item : items) {
            int factor = item[0];
            int price = item[1];

            freq[factor]++;
            minPrice = min(minPrice, price);
        }

        // Count how many item types each factor can unlock
        vector<int> gain(n + 1, 0);

        for (int f = 1; f <= n; f++) {
            for (int multiple = f; multiple <= n; multiple += f) {
                gain[f] += freq[multiple];
            }

            // Cannot receive itself for free
            gain[f]--;
        }

        // Store eligible bonus purchases: {price, gain}
        vector<pair<int, int>> candidates;

        for (auto& item : items) {
            int factor = item[0];
            int price = item[1];

            if (gain[factor] > 0 && price < 2LL * minPrice) {
                candidates.push_back({price, gain[factor]});
            }
        }

        // Buy cheapest bonus items first
        sort(candidates.begin(), candidates.end());

        long long ans = 0;
        long long remaining = budget;

        for (auto [price, count] : candidates) {
            long long take = min(
                (long long)count,
                remaining / price
            );

            ans += 2 * take;
            remaining -= take * price;
        }

        // Spend remaining budget on cheapest items
        ans += remaining / minPrice;

        return (int)ans;
    }
};
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> left, right;
        long long leftSum = 0, rightSum = 0;

        auto rebalance = [&]() {
            while (left.size() > right.size() + 1) {
                int val = *left.rbegin();
                left.erase(left.find(val));
                leftSum -= val;

                right.insert(val);
                rightSum += val;
            }

            while (left.size() < right.size()) {
                int val = *right.begin();
                right.erase(right.find(val));
                rightSum -= val;

                left.insert(val);
                leftSum += val;
            }
        };

        auto add = [&](int val) {
            if (left.empty() || val <= *left.rbegin()) {
                left.insert(val);
                leftSum += val;
            } else {
                right.insert(val);
                rightSum += val;
            }

            rebalance();
        };

        auto remove = [&](int val) {
            auto it = left.find(val);

            if (it != left.end()) {
                left.erase(it);
                leftSum -= val;
            } else {
                it = right.find(val);
                right.erase(it);
                rightSum -= val;
            }

            rebalance();
        };

        auto getCost = [&]() -> long long {
            long long median = *left.rbegin();

            return median * (long long)left.size() - leftSum
                 + rightSum - median * (long long)right.size();
        };

        vector<long long> cost(n - x + 1);

        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }

        cost[0] = getCost();

        for (int i = x; i < n; i++) {
            remove(nums[i - x]);
            add(nums[i]);

            cost[i - x + 1] = getCost();
        }

        const long long INF = 1e18;

        vector<vector<long long>> dp(
            k + 1, vector<long long>(n + 1, INF)
        );

        dp[0][0] = 0;

        for (int i = 0; i < n; i++) {
            for (int used = 0; used <= k; used++) {
                if (dp[used][i] == INF)
                    continue;

                // Skip current position
                dp[used][i + 1] = min(
                    dp[used][i + 1],
                    dp[used][i]
                );

                // Select a subarray of length x
                if (used < k && i + x <= n) {
                    dp[used + 1][i + x] = min(
                        dp[used + 1][i + x],
                        dp[used][i] + cost[i]
                    );
                }
            }
        }

        return *min_element(dp[k].begin(), dp[k].end());
    }
};
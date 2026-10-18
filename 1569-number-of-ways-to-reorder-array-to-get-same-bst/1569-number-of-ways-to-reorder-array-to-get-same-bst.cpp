
class Solution {
public:
    long long MOD = 1e9 + 7;
    long long dp[1001][1001] = {};

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i <= n; i++) {
            dp[i][0] = dp[i][i] = 1;
            for (int j = 1; j < i; j++) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
            }
        }

        return (ways(nums) - 1 + MOD) % MOD;
    }

    long long ways(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2) return 1;

        vector<int> left, right;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0])
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        long long l = ways(left);
        long long r = ways(right);

        long long combinations = dp[n - 1][left.size()];

        return combinations * l % MOD * r % MOD;
    }
};


class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        long long ans = 0;

        vector<int> freq(32, 0);

        // Count set bits at each position
        for (int num : nums) {
            for (int bit = 0; bit < 32; bit++) {
                if (num & (1 << bit)) {
                    freq[bit]++;
                }
            }
        }

        // Construct k maximum numbers
        for (int i = 0; i < k; i++) {
            long long num = 0;

            for (int bit = 31; bit >= 0; bit--) {
                if (freq[bit] > 0) {
                    num |= (1LL << bit);
                    freq[bit]--;
                }
            }

            ans = (ans + num * num) % MOD;
        }

        return ans;
    }
};

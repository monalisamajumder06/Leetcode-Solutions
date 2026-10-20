
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; ++k) {
            if (n % k != 0) continue;

            bool ok = true;
            int prevMax = 0;

            for (int start = 0; start < n; start += k) {
                int descents = 0;
                int mn = nums[start];
                int mx = nums[start];

                for (int i = start; i < start + k; ++i) {
                    mn = min(mn, nums[i]);
                    mx = max(mx, nums[i]);

                    if (i > start && nums[i - 1] > nums[i]) {
                        ++descents;
                    }
                }

                if (nums[start + k - 1] > nums[start]) {
                    ++descents;
                }

                if (descents > 1) {
                    ok = false;
                    break;
                }

                if (start > 0 && prevMax > mn) {
                    ok = false;
                    break;
                }

                prevMax = mx;
            }

            if (ok) {
                ans += k;
            }
        }

        return ans;
    }
};

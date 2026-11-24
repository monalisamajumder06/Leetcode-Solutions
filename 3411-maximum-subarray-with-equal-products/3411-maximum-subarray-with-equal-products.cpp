class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            bool valid = true;

            for (int j = i; j < n; j++) {
                for (int k = i; k < j; k++) {
                    if (__gcd(nums[k], nums[j]) != 1)
                        valid = false;
                }

                if (j - i < 2 || valid)
                    ans = max(ans, j - i + 1);
                else
                    break;
            }
        }

        return ans;
    }
};
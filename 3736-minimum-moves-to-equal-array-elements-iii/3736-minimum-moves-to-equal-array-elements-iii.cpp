class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int ans = 0;

        for (int num : nums) {
            ans += maxVal - num;
        }

        return ans;
    }
};
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;

        long long even = 1, odd = 0;
        long long prefix = 0;
        long long ans = 0;

        for (int x : arr) {
            prefix += x;

            if (prefix % 2 == 0) {
                ans += odd;
                even++;
            } 
            else {
                ans += even;
                odd++;
            }

            ans %= MOD;
        }

        return ans;
    }
};
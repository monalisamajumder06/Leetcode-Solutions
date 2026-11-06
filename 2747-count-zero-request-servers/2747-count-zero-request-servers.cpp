class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {
        int m = queries.size();

        vector<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());
        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        vector<int> ans(m, 0);
        vector<int> cnt(n + 1, 0);

        int left = 0, right = 0;
        int active = 0;

        for (auto& query : q) {
            int t = query.first;
            int idx = query.second;

            // Add logs within the window [t-x, t]
            while (right < logs.size() && logs[right][1] <= t) {
                int server = logs[right][0];

                if (cnt[server] == 0) {
                    active++;
                }

                cnt[server]++;
                right++;
            }

            // Remove logs outside the window
            while (left < right && logs[left][1] < t - x) {
                int server = logs[left][0];

                cnt[server]--;

                if (cnt[server] == 0) {
                    active--;
                }

                left++;
            }

            ans[idx] = n - active;
        }

        return ans;
    }
};
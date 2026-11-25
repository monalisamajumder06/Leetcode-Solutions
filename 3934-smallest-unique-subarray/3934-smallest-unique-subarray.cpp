class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        // Build suffix array
        vector<int> a = nums;
        a.push_back(0); // Sentinel

        int m = n + 1;
        vector<int> sa(m), c(m);

        vector<pair<int, int>> p(m);

        for (int i = 0; i < m; i++)
            p[i] = {a[i], i};

        sort(p.begin(), p.end());

        for (int i = 0; i < m; i++)
            sa[i] = p[i].second;

        c[sa[0]] = 0;

        for (int i = 1; i < m; i++) {
            c[sa[i]] = c[sa[i - 1]] +
                       (p[i].first != p[i - 1].first);
        }

        int k = 0;

        while ((1 << k) < m) {
            for (int i = 0; i < m; i++)
                sa[i] = (sa[i] - (1 << k) + m) % m;

            vector<int> cnt(m), new_sa(m);

            for (int x : c)
                cnt[x]++;

            for (int i = 1; i < m; i++)
                cnt[i] += cnt[i - 1];

            for (int i = m - 1; i >= 0; i--)
                new_sa[--cnt[c[sa[i]]]] = sa[i];

            sa = new_sa;

            vector<int> new_c(m);
            new_c[sa[0]] = 0;

            for (int i = 1; i < m; i++) {
                pair<int, int> cur = {
                    c[sa[i]], c[(sa[i] + (1 << k)) % m]
                };

                pair<int, int> prev = {
                    c[sa[i - 1]],
                    c[(sa[i - 1] + (1 << k)) % m]
                };

                new_c[sa[i]] = new_c[sa[i - 1]]
                               + (cur != prev);
            }

            c = new_c;
            k++;
        }

        // Remove sentinel suffix
        sa.erase(sa.begin());

        // Build LCP array using Kasai's algorithm
        vector<int> rank(n), lcp(n, 0);

        for (int i = 0; i < n; i++)
            rank[sa[i]] = i;

        int h = 0;

        for (int i = 0; i < n; i++) {
            int r = rank[i];

            if (r == n - 1) {
                h = 0;
                continue;
            }

            int j = sa[r + 1];

            while (i + h < n && j + h < n &&
                   nums[i + h] == nums[j + h]) {
                h++;
            }

            lcp[r] = h;

            if (h > 0)
                h--;
        }

        // Find minimum unique substring length
        int ans = n;

        for (int i = 0; i < n; i++) {
            int common = 0;

            if (i > 0)
                common = max(common, lcp[i - 1]);

            if (i < n - 1)
                common = max(common, lcp[i]);

            int len = common + 1;

            if (sa[i] + len <= n)
                ans = min(ans, len);
        }

        return ans;
    }
};
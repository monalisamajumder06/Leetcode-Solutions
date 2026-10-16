
class Solution {
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum = 0;
        long long sq = 0;
        long long lazy = 0;
    };

    vector<Node> seg;
    int n;

    void apply(int node, int l, int r, long long d) {
        long long len = r - l + 1;
        long long oldSum = seg[node].sum;

        seg[node].sq =
            (seg[node].sq
             + 2LL * d % MOD * oldSum % MOD
             + len % MOD * d % MOD * d % MOD) % MOD;

        seg[node].sum =
            (oldSum + len % MOD * d % MOD) % MOD;

        seg[node].lazy = (seg[node].lazy + d) % MOD;
    }

    void push(int node, int l, int r) {
        if (seg[node].lazy == 0 || l == r)
            return;

        int mid = l + (r - l) / 2;
        long long d = seg[node].lazy;

        apply(node * 2, l, mid, d);
        apply(node * 2 + 1, mid + 1, r, d);

        seg[node].lazy = 0;
    }

    void update(int node, int l, int r,
                int ql, int qr, long long d) {
        if (ql > r || qr < l)
            return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, d);
            return;
        }

        push(node, l, r);

        int mid = l + (r - l) / 2;

        update(node * 2, l, mid, ql, qr, d);
        update(node * 2 + 1, mid + 1, r, ql, qr, d);

        seg[node].sum =
            (seg[node * 2].sum +
             seg[node * 2 + 1].sum) % MOD;

        seg[node].sq =
            (seg[node * 2].sq +
             seg[node * 2 + 1].sq) % MOD;
    }

    long long query(int node, int l, int r,
                    int ql, int qr) {
        if (ql > r || qr < l)
            return 0;

        if (ql <= l && r <= qr)
            return seg[node].sq;

        push(node, l, r);

        int mid = l + (r - l) / 2;

        return (query(node * 2, l, mid, ql, qr)
              + query(node * 2 + 1, mid + 1, r, ql, qr))
              % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        seg.assign(4 * n + 5, Node());

        unordered_map<int, int> last;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int prev = -1;

            if (last.count(nums[i]))
                prev = last[nums[i]];

            // Add one to all affected starting indices.
            update(1, 0, n - 1, prev + 1, i, 1);

            // Sum of squared distinct counts for subarrays
            // ending at index i.
            ans = (ans + query(1, 0, n - 1, 0, i))
                  % MOD;

            last[nums[i]] = i;
        }

        return ans;
    }
};

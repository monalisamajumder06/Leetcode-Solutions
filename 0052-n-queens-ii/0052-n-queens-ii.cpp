class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n, false); // r + c
        vector<bool> diag2(2 * n, false); // r - c + n
        
        backtrack(0, n, count, cols, diag1, diag2);
        return count;
    }

private:
    void backtrack(int r, int n, int& count, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2) {
        if (r == n) {
            count++;
            return;
        }

        for (int c = 0; c < n; c++) {
            if (cols[c] || diag1[r + c] || diag2[r - c + n]) {
                continue;
            }

            cols[c] = diag1[r + c] = diag2[r - c + n] = true;
            backtrack(r + 1, n, count, cols, diag1, diag2);
            cols[c] = diag1[r + c] = diag2[r - c + n] = false;
        }
    }
};
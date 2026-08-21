class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        vector<vector<int>> memo(n, vector<int>(n, -1));

        auto getSum = [&](int l, int r) {
            return prefix[r + 1] - prefix[l];
        };

        auto solve = [&](auto& self, int l, int r) -> int {
            if (l >= r) return 0;
            if (memo[l][r] != -1) return memo[l][r];

            int maxScore = 0;
            for (int k = l; k < r; ++k) {
                int leftSum = getSum(l, k);
                int rightSum = getSum(k + 1, r);

                if (leftSum < rightSum) {
                    maxScore = max(maxScore, leftSum + self(self, l, k));
                } else if (leftSum > rightSum) {
                    maxScore = max(maxScore, rightSum + self(self, k + 1, r));
                } else {
                    maxScore = max(maxScore, leftSum + max(self(self, l, k), self(self, k + 1, r)));
                }
            }

            return memo[l][r] = maxScore;
        };

        return solve(solve, 0, n - 1);
    }
};
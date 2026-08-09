class Solution {
public:
    int n;
    vector<int> suffix;
    vector<vector<int>> dp;

    int solve(int i, int M) {

        if (i >= n)
            return 0;

        // Can take all remaining piles
        if (2 * M >= n - i)
            return suffix[i];

        if (dp[i][M] != -1)
            return dp[i][M];

        int best = 0;

        for (int x = 1; x <= 2 * M && i + x <= n; x++) {

            int opponent = solve(
                i + x,
                max(M, x)
            );

            int current = suffix[i] - opponent;

            best = max(best, current);
        }

        return dp[i][M] = best;
    }

    int stoneGameII(vector<int>& piles) {

        n = piles.size();

        suffix.resize(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
            suffix[i] = suffix[i + 1] + piles[i];

        dp.assign(n, vector<int>(n + 1, -1));

        return solve(0, 1);
    }
};
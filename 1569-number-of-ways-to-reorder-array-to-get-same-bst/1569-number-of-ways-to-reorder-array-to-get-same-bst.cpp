class Solution {
public:
    const long long mod = 1e9 + 7;
    vector<vector<long long>> comb;

    long long solve(vector<int>& nums) {
        int n = nums.size();

        if(n <= 2)
            return 1;

        vector<int> left, right;

        for(int i = 1; i < n; i++)
        {
            if(nums[i] < nums[0])
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        long long a = solve(left);
        long long b = solve(right);

        return comb[n - 1][left.size()] * a % mod * b % mod;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        comb.assign(n + 1, vector<long long>(n + 1, 0));

        for(int i = 0; i <= n; i++)
        {
            comb[i][0] = 1;
            comb[i][i] = 1;

            for(int j = 1; j < i; j++)
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
        }

        return (solve(nums) - 1 + mod) % mod;
    }
};
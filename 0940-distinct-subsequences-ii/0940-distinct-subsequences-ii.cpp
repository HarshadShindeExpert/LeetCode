class Solution {
public:
    int distinctSubseqII(string s) {
        const long long mod = 1e9 + 7;
        vector<long long> dp(26, 0);

        for(char c : s)
        {
            int i = c - 'a';

            long long sum = 1;

            for(int j = 0; j < 26; j++)
                sum = (sum + dp[j]) % mod;

            dp[i] = sum;
        }

        long long ans = 0;

        for(int i = 0; i < 26; i++)
            ans = (ans + dp[i]) % mod;

        return ans;
    }
};
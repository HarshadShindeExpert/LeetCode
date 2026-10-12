class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long mod = 1e9 + 7;
        vector<int> count(31, 0);

        for(int x : nums)
        {
            for(int i = 0; i < 31; i++)
            {
                if((x >> i) & 1)
                    count[i]++;
            }
        }

        long long ans = 0;

        for(int i = 0; i < k; i++)
        {
            long long num = 0;

            for(int j = 0; j < 31; j++)
            {
                if(count[j] > 0)
                {
                    num |= (1LL << j);
                    count[j]--;
                }
            }

            ans = (ans + num * num) % mod;
        }

        return ans;
    }
};

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> dp(n + 1, INT_MAX);

        int left = 0;
        int sum = 0;
        int ans = INT_MAX;

        for(int right = 0; right < n; right++)
        {
            sum += arr[right];

            while(sum > target)
            {
                sum -= arr[left];
                left++;
            }

            dp[right + 1] = dp[right];

            if(sum == target)
            {
                int len = right - left + 1;

                if(dp[left] != INT_MAX)
                    ans = min(ans, len + dp[left]);

                dp[right + 1] = min(dp[right + 1], len);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
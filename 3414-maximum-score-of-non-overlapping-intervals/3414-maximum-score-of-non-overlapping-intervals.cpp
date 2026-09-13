class Solution {
public:
    struct Node {
        long long sum;
        vector<int> ids;
    };

    bool better(Node a, Node b) {
        if(a.sum != b.sum)
            return a.sum > b.sum;

        return a.ids < b.ids;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<long long, 4>> v(n);

        for(int i = 0; i < n; i++)
        {
            v[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        sort(v.begin(), v.end());

        vector<vector<Node>> dp(n + 1, vector<Node>(5));

        for(int i = n - 1; i >= 0; i--)
        {
            for(int k = 1; k <= 4; k++)
            {
                dp[i][k] = dp[i + 1][k];

                long long l = v[i][0];
                long long r = v[i][1];
                long long w = v[i][2];
                int id = v[i][3];

                int next = upper_bound(
                    v.begin(),
                    v.end(),
                    array<long long, 4>{r, LLONG_MAX, LLONG_MAX, LLONG_MAX}
                ) - v.begin();

                Node take = dp[next][k - 1];
                take.sum += w;
                take.ids.push_back(id);

                sort(take.ids.begin(), take.ids.end());

                if(better(take, dp[i][k]))
                    dp[i][k] = take;
            }
        }

        return dp[0][4].ids;
    }
};
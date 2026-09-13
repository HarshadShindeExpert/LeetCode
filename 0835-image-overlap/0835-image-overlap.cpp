class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> a, b;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(img1[i][j] == 1)
                    a.push_back({i, j});

                if(img2[i][j] == 1)
                    b.push_back({i, j});
            }
        }

        map<pair<int,int>, int> count;
        int ans = 0;

        for(auto x : a)
        {
            for(auto y : b)
            {
                int dx = x.first - y.first;
                int dy = x.second - y.second;

                count[{dx, dy}]++;
                ans = max(ans, count[{dx, dy}]);
            }
        }

        return ans;
    }
};

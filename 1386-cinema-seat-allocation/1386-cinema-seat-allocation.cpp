class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        for(auto x : reservedSeats)
            mp[x[0]] |= 1 << x[1];

        int ans = (n - mp.size()) * 2;

        for(auto x : mp)
        {
            int mask = x.second;
            bool left = !(mask & (1 << 2)) && !(mask & (1 << 3)) && !(mask & (1 << 4)) && !(mask & (1 << 5));
            bool right = !(mask & (1 << 6)) && !(mask & (1 << 7)) && !(mask & (1 << 8)) && !(mask & (1 << 9));
            bool middle = !(mask & (1 << 4)) && !(mask & (1 << 5)) && !(mask & (1 << 6)) && !(mask & (1 << 7));

            if(left && right)
                ans += 2;
            else if(left || right || middle)
                ans += 1;
        }

        return ans;
    }
};
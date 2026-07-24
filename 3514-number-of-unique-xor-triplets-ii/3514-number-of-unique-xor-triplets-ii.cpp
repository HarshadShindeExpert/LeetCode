class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<bool> one(MAXX, false);
        vector<bool> two(MAXX, false);
        vector<bool> three(MAXX, false);

        // XOR of one element
        for (int x : nums)
            one[x] = true;

        // XOR of two elements (i <= j)
        for (int x = 0; x < MAXX; x++) {
            if (!one[x]) continue;
            for (int y : nums)
                two[x ^ y] = true;
        }

        // XOR of three elements (i <= j <= k)
        for (int x = 0; x < MAXX; x++) {
            if (!two[x]) continue;
            for (int y : nums)
                three[x ^ y] = true;
        }

        int ans = 0;
        for (bool b : three)
            ans += b;

        return ans;
    }
};
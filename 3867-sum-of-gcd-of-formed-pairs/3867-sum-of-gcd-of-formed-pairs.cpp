class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long sum = 0;

        if (nums.size() == 1)
            return 0;

        vector<int> prefixGCD;

        int mx = nums[0];
        prefixGCD.push_back(mx);

        for (int i = 1; i < nums.size(); i++) {
            mx = max(mx, nums[i]);
            prefixGCD.push_back(gcd(mx, nums[i]));
        }

        sort(prefixGCD.begin(), prefixGCD.end());

        int i = 0;
        int j = prefixGCD.size() - 1;

        while (i < j) {
            sum += gcd(prefixGCD[i], prefixGCD[j]);
            i++;
            j--;
        }

        return sum;
    }
};
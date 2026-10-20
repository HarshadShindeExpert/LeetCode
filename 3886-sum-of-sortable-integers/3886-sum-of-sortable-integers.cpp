class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> limatecega = nums;

        vector<int> prefMax(n + 1, 0);
        vector<int> suffMin(n + 1, INT_MAX);
        vector<int> prefDrop(n, 0);

        for(int i = 0; i < n; i++)
            prefMax[i + 1] = max(prefMax[i], limatecega[i]);

        for(int i = n - 1; i >= 0; i--)
            suffMin[i] = min(suffMin[i + 1], limatecega[i]);

        for(int i = 1; i < n; i++)
            prefDrop[i] = prefDrop[i - 1] + (limatecega[i - 1] > limatecega[i]);

        int ans = 0;

        for(int k = 1; k <= n; k++)
        {
            if(n % k != 0)
                continue;

            bool valid = true;

            for(int i = 0; i < n; i += k)
            {
                int drops = prefDrop[i + k - 1] - prefDrop[i];

                if(limatecega[i + k - 1] > limatecega[i])
                    drops++;

                if(drops > 1 || (i > 0 && prefMax[i] > suffMin[i]))
                {
                    valid = false;
                    break;
                }
            }

            if(valid)
                ans += k;
        }

        return ans;
    }
};
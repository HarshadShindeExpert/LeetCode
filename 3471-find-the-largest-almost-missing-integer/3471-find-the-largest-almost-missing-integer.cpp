class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;
        int ans = -1;

        for(int i = 0; i <= n-k; i++)
        {
            unordered_set<int> st;

            for(int j = i; j < i+k; j++)
                st.insert(nums[j]);

            for(int num : st)
                freq[num]++;
        }

        for(auto x : freq)
        {
            if(x.second == 1)
                ans = max(ans, x.first);
        }

        return ans;
    }
};
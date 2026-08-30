class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if(nums.size() == 1) return 1;

        int maximum = INT_MIN;
        int minimum = INT_MAX;
        int min_idx = 0, max_idx = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > maximum)
            {
                maximum = nums[i];
                max_idx = i;
            }

            if(nums[i] < minimum)
            {
                minimum = nums[i];
                min_idx = i;
            }
        }

        int max_ele = max(max_idx, min_idx);
        int min_ele = min(max_idx, min_idx);

        int front = max_ele + 1;
        int back = nums.size() - min_ele;
        int both = min_ele + 1 + nums.size() - max_ele;

        return min({front, back, both});
    }
};
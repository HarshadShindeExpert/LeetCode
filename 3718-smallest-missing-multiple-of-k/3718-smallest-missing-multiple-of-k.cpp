class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> mul;
        for(int i=0 ; i<nums.size() ; i++)
            {
                if(nums[i]%k==0)
                {
                    mul.push_back(nums[i]);
                }
            }
        int n=k;
        sort(mul.begin() ,mul.end());
        mul.erase(unique(mul.begin(), mul.end()), mul.end());
        for(int i=0 ; i<mul.size() ; i++)
            {
                if(n!=mul[i])
                {
                    break;
                }
                n+=k;
            }
        return n;
    }
};
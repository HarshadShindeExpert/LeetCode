class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans ;
        if(nums.size() == 0 || nums.size() == 1)
        {
            return ans ;
        }
        sort(nums.begin() , nums.end());
        int start = nums[0] ;
        for(int i=1 ; i < nums.size() ; i++)
        {
            start ++ ;
            int current = nums[i] ;
            if(start != current)
            {
                while(start < current)
                {
                    ans.push_back(start);
                    start ++ ;
                }
            }
        }
        return ans ;
    }
};
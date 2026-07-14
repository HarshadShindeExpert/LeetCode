class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int high  , low ;
        int h_index , l_index ;
        h_index = nums.size()-1;
        
        l_index = 0 ;
        
        int sum ;
        vector<int> ans ;
        while(l_index<h_index)
        {
            high = nums[h_index];
            low = nums[l_index];

            sum = low + high ;
            if(sum == target)
            {
                ans.push_back(l_index+1);
                ans.push_back(h_index+1);
                return ans ;
            }
            if(sum < target)
            {
                l_index++;
            }
            else
                h_index--;
        }
        return ans ;
    }
};
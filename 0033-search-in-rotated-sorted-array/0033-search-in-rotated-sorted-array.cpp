class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0 , high=nums.size()-1 , mid ;
        if(nums.size()==1)
        {
            if(nums[0]==target) return 0;
            return -1 ;
        }
        for(int i=0 ; i<nums.size()-1 ; i++)
        {
            if(nums[i]>nums[i+1])
            {
                if(target <= nums[i] && target >= nums[0])
                {
                    low = 0 ;
                    high = i ;
                }
                else 
                {
                    low = i+1;
                    high = nums.size()-1;
                }
                break ;
            }
        }
        while(low <= high )
        {
            mid = low + ((high-low)/2);
            if(nums[mid] == target)
            {
                return mid ;
            }
            else if(target > nums[mid])
            {
                low = mid+1;
            }
            else
            {
                high = mid-1 ;
            }
        }
        return -1;
    }
};
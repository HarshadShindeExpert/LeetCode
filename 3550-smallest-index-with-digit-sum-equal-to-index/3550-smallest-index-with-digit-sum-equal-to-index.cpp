class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int dig , sum ;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            sum = 0 ;
            while(nums[i] > 0)
            {
                sum = sum + ( nums[i] % 10) ;
                nums[i] = nums[i] / 10 ;
            }
            if( sum == i)
            {
                return i ;
            }
               
        }
        return -1 ;
    }
};
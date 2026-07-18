class Solution {
public:
    int findGCD(vector<int>& nums) {
        int smallest = INT_MAX;
        int largest= 0 ;
        for(int i=0 ; i < nums.size() ; i++)
        {
            if(largest < nums[i]) largest = nums[i] ;
            if(smallest > nums[i]) smallest= nums[i];
        }
        return gcd(smallest , largest);
    }
};
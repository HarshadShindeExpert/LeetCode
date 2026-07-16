class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long sum = 0 ;
        vector<int> prefixGCD ;
        int max = nums[0];
        int curr ;
        if(nums.size()==1) return 0 ;
        prefixGCD.push_back(max);
        for(int i=1 ; i<nums.size() ; i++)
        {
            curr =nums[i] ;
            if(nums[i] > max ) max = nums[i] ;
            int gc = gcd(max , curr);
            prefixGCD.push_back(gc);
        }

        int i=0 ; 
        int j=prefixGCD.size()-1 ;
        sort(prefixGCD.begin() , prefixGCD.end());
        while(i<j)
        {
            sum += gcd(prefixGCD[i] , prefixGCD[j]);
            i++;
            j--;
        }
        return sum ;
    }
};
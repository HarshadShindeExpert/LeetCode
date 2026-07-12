class Solution {
public:
    void sortColors(vector<int>& nums) {
       vector<int> count(3,0);
       for(int i=0 ; i<nums.size() ; i++)
       {
        count[nums[i]] ++ ;
       }
       int start = 0 ;
       for(int i=0 ; i<3 ; i++)
       {
        int cnt = count[i];
        while(cnt>0)
        {
            nums[start] = i ;
            cnt -- ;
            start++;
        }
       }
       return ;
    }
};
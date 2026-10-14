class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        int dig ;
        if(9*num < sum )
            return ans ;
        while(sum >= 9)
        {
            ans += "9" ;
            sum -= 9 ;
        }
        if(sum > 0)
        {
            ans += '0' + sum  ;
        }
        int diff = num - ans.size() ;
        for(int i=0 ; i < diff ; i++ )
        {
            ans += "0" ;
        }
        return ans ;
    }
};
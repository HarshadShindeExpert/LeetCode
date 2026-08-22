class Solution {
public:
    bool checkDivisibility(int n) {
        int num = n ;
        int dig ;
        int sum = 0 ;
        int pro = 1 ;
        while(n > 0)
        {
            dig = n % 10 ;
            sum += dig ;
            pro *= dig ;
            n = n / 10 ;
        }
        if(num % (pro + sum ) == 0)
            return true ;
        return false ;
    }
};
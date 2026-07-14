class Solution {
public:
    bool judgeSquareSum(int c) {
        long long last = sqrt(c);
        long long i=0;
        while(i<=last)
        {
            long long sum = (i*i) + (last*last);
            if(sum == c) return true;
            else if(sum < c) i++;
            else last--;
        }
        return false ;
    }
};
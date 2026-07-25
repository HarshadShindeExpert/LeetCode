class Solution {
public:
    int maxProduct(int n) {
        vector<int> digits ;
        digits.push_back(0);
        while(n>0)
        {
            int num = n % 10 ;
            digits.push_back(num);
            n = n/10 ;
        }
        sort(digits.begin() , digits.end() , greater<int>());
        return digits[0]*digits[1];
    }
};
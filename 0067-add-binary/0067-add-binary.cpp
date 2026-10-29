class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0 ;
        int s1 = a.size() - 1 , s2 = b.size() - 1 ;
        string ans = "";
        
        while(s1 >= 0 && s2 >= 0)
        {
            int sum = (a[s1] - '0') + (b[s2] - '0') + carry ;
            carry = sum / 2 ;
            ans += to_string(sum % 2);
            s1-- ;
            s2-- ;
        }
        while(s1 >= 0){
            int sum = (a[s1] - '0') + carry ;
            carry = sum / 2 ;
            ans += to_string(sum % 2);
            s1-- ;
        }
        while(s2 >= 0){
            int sum = (b[s2] - '0') + carry ;
            carry = sum / 2 ;
            ans += to_string(sum % 2);
            s2-- ;
        }
        
        if(carry == 1 )
        {
            ans += to_string(carry);
        }
        
        reverse(ans.begin() , ans.end());
        return ans;
    }
};
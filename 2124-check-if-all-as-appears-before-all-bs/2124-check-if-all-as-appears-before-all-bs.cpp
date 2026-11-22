class Solution {
public:
    bool checkString(string s) {
        bool check_b = false ;
        for(int i=0 ; i<s.size() ; i++)
        {
            if(s[i] == 'a' && check_b == false) continue ;
            if(s[i] == 'a' && check_b == true ) return false ;
            if(s[i] == 'b') check_b = true ;
        }
        return true ;
    }
};
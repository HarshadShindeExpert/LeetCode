class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0 ;
        stack<char> store ;
        int n = s.size() ;
        for(int i = 0 ; i < n ; i++)
        {
            if(s[i] == ')' && store.empty())
            {
                count ++ ;
            }
            else if(s[i] == ')' && !store.empty())
            {
                store.pop();
            }
            else
            {
                store.push(s[i]);
            }
        }
        while(!store.empty())
        {
            count ++ ;
            store.pop() ;
        }
        return count ;

    }
};
class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        int nums = 0 ;
        vector<int> count (26 , 0 );
        for(int i=0 ; i<word.length() ; i++)
        {
            count[word[i] - 'a'] +=1 ;
        }
        sort(count.begin() , count.end() , greater<int>());

        for (int i = 0; i < 26; i++) {
            int idx = i/8 +1 ;
            ans += (count[i] * idx) ;
        }

        return ans;
    }
};
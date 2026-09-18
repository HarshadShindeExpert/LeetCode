class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<int> first(26, n);
        vector<int> last(26, -1);

        for(int i = 0; i < n; i++)
        {
            int x = s[i] - 'a';
            first[x] = min(first[x], i);
            last[x] = i;
        }

        vector<pair<int,int>> intervals;

        for(int c = 0; c < 26; c++)
        {
            if(last[c] == -1)
                continue;

            int l = first[c];
            int r = last[c];
            bool valid = true;

            for(int i = l; i <= r; i++)
            {
                int x = s[i] - 'a';

                if(first[x] < l)
                {
                    valid = false;
                    break;
                }

                r = max(r, last[x]);
            }

            if(valid)
                intervals.push_back({r, l});
        }

        sort(intervals.begin(), intervals.end());

        vector<string> ans;
        int prev = -1;

        for(auto p : intervals)
        {
            int r = p.first;
            int l = p.second;

            if(l > prev)
            {
                ans.push_back(s.substr(l, r - l + 1));
                prev = r;
            }
        }

        return ans;
    }
};
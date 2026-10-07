class Solution {
public:
    set<string> ans;
    int n;

    void solve(string &s, int i, int left, int right, int open, int close, string temp)
    {
        if(i == n)
        {
            if(left == 0 && right == 0)
                ans.insert(temp);

            return;
        }

        if(n - i < left + right)
            return;

        if(open < close)
            return;

        if(s[i] == '(' && left > 0)
        {
            solve(s, i + 1, left - 1, right, open, close, temp);
        }

        if(s[i] == ')' && right > 0)
        {
            solve(s, i + 1, left, right - 1, open, close, temp);
        }

        if(s[i] == '(')
            solve(s, i + 1, left, right, open + 1, close, temp + s[i]);
        else if(s[i] == ')')
        {
            if(open > close)
                solve(s, i + 1, left, right, open, close + 1, temp + s[i]);
        }
        else
            solve(s, i + 1, left, right, open, close, temp + s[i]);
    }

    vector<string> removeInvalidParentheses(string s) {
        n = s.size();

        int left = 0;
        int right = 0;

        for(char c : s)
        {
            if(c == '(')
                left++;
            else if(c == ')')
            {
                if(left > 0)
                    left--;
                else
                    right++;
            }
        }

        solve(s, 0, left, right, 0, 0, "");

        return vector<string>(ans.begin(), ans.end());
    }
};
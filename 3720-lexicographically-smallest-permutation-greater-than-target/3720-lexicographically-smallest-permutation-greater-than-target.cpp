class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);

        for(char c : s)
            freq[c - 'a']++;

        string ans = "";

        for(int i = 0; i < target.size(); i++)
        {
            int x = target[i] - 'a';

            if(freq[x] > 0)
            {
                ans += target[i];
                freq[x]--;
            }
            else
            {
                for(int j = i; j >= 0; j--)
                {
                    if(j < i)
                        freq[target[j] - 'a']++;

                    int y = target[j] - 'a';

                    for(int k = y + 1; k < 26; k++)
                    {
                        if(freq[k] > 0)
                        {
                            string res = target.substr(0, j);
                            res += char('a' + k);
                            freq[k]--;

                            for(int p = 0; p < 26; p++)
                                res += string(freq[p], char('a' + p));

                            return res;
                        }
                    }
                }

                return "";
            }
        }

        for(int i = target.size() - 1; i >= 0; i--)
        {
            int x = target[i] - 'a';
            freq[x]++;

            for(int j = x + 1; j < 26; j++)
            {
                if(freq[j] > 0)
                {
                    string res = target.substr(0, i);
                    res += char('a' + j);
                    freq[j]--;

                    for(int k = 0; k < 26; k++)
                        res += string(freq[k], char('a' + k));

                    return res;
                }
            }
        }

        return "";
    }
};
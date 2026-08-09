class Solution {
public:
    vector<int> validSequence(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        // suf[i] = first unmatched position in word2
        // after matching word2 from right using word1[i...].
        vector<int> suf(n + 1);

        suf[n] = m;

        int j = m - 1;

        for (int i = n - 1; i >= 0; i--) {

            if (j >= 0 && word1[i] == word2[j])
                j--;

            suf[i] = j + 1;
        }

        vector<int> ans;

        int j2 = 0;
        bool mismatchUsed = false;

        for (int i = 0; i < n && j2 < m; i++) {

            // Exact match
            if (word1[i] == word2[j2]) {

                ans.push_back(i);
                j2++;
            }

            // Use this position as the one mismatch
            else if (!mismatchUsed && suf[i + 1] <= j2 + 1) {

                ans.push_back(i);
                j2++;
                mismatchUsed = true;
            }
        }

        if (ans.size() == m)
            return ans;

        return {};
    }
};
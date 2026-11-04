class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 1. Collect all unique sorted anagram signatures using a set
        set<string> uniqueSignatures;
        for (const string& s : strs) {
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end());
            uniqueSignatures.insert(sorted_s);
        }
        
        // 2. Map each unique signature to a specific index in our answer vector
        // We use a vector of strings to match the order of uniqueSignatures
        vector<string> signatureList(uniqueSignatures.begin(), uniqueSignatures.end());
        
        // 3. Initialize the answer vector with an empty sub-vector for each unique signature
        vector<vector<string>> ans(signatureList.size());
        
        // 4. Group the original strings by finding their sorted signature's index
        for (const string& s : strs) {
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end());
            
            // Binary search (std::lower_bound) to find the index in O(log M) time
            auto it = lower_bound(signatureList.begin(), signatureList.end(), sorted_s);
            int groupIndex = distance(signatureList.begin(), it);
            
            ans[groupIndex].push_back(s);
        }
        
        return ans;
    }
};

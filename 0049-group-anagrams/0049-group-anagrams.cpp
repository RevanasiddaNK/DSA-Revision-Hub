class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (const string& str : strs) {
            // Create a frequency-based key
            vector<int> freq(26, 0);
            for (char ch : str) {
                freq[ch - 'a']++;
            }

            // Convert frequency array to a unique string key
            string key;
            for (int count : freq) {
                key += '#' + to_string(count);
            }

            // Group the original string using this frequency key
            mp[key].push_back(str);
        }

        // Collect all anagram groups from the hashmap
        vector<vector<string>> ans;
        for (const auto& entry : mp) {
            ans.push_back(entry.second);
        }

        return ans;
    }
};
/*
Complexity Analysis
    Time Complexity: O(N×K)
    Space Complexity: O(N×K)
*/

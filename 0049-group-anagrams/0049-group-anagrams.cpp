class Solution {
public:

    vector<vector<string>> groupAnagramsBySorting(vector<string>& strs) {
        unordered_map<string, vector<string> >mp;
        vector<string>anagrams;
        int n = strs.size();
        for(int i=0; i<n ; i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if(mp.find(temp) != mp.end()){
                mp[temp].push_back(strs[i]);
            }
            else{
                mp[temp].push_back(strs[i]);
                anagrams.push_back(temp);
            }
        }
        vector<vector<string>>ans;
        for(int i=0; i<anagrams.size(); i++){
            ans.push_back(mp[anagrams[i]]);
        }

        return ans;

    }

    

vector<vector<string>> groupAnagramsByFrequency(vector<string>& strs) {
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


    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        /*
        Complexity Analysis Method 1 : By Sorting
            Time Complexity: O(N× K*log(K) )
            Space Complexity: O(N×K)
        */
        //return groupAnagramsBySorting(strs);

        /*
        Complexity Analysis
            Time Complexity: O(N×K)
            Space Complexity: O(N×K)
        */

        return groupAnagramsByFrequency(strs);


    }
};
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
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
};
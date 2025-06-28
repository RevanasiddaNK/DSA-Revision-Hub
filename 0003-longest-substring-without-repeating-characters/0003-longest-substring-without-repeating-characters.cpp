class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>seen;
        int ans=-1;
        int i=0,j=0;
        int n = s.size();
        while(j<n){
            if(seen.find(s[j]) == seen.end()){
                seen.insert(s[j]);
                ans = max(ans, abs(j-i+1));
                j++;
            }else{
                seen.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};
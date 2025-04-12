class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int i=0, j=0;
        int n1=word1.size(), n2=word2.size();
        while(i<n1 && j<n2){
            ans.push_back(word1[i++]);
            ans.push_back(word2[j++]);
        }

        while(i<n1){
            ans.push_back(word1[i++]);
        }

        while(j<n2){
            ans.push_back(word2[j++]);
        }
        
        return ans;
    }
};
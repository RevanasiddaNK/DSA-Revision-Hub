class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_map<string,bool>mp;
        for(string s : bannedWords)
            mp[s] = true;
        int count = 0;
        for(string s : message){
            if(mp.find(s) != mp.end()){
                count++;
            }
        }
        if(count >= 2 ){
            return 1;
        }
        else{
            return 0;
        }
    }
};

/*
        TC : O(N)
        SC: O(N)
*/
class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_map<string,bool>mp;
        vector<string>ans;
        string seg = "";
        mp[seg] = 1;
        for(char ch : s){
            
            if(mp.find(seg) == mp.end() ){
                ans.push_back(seg);
                mp[seg] = 1;
                seg = "";
                seg.push_back(ch);
            }else{
                seg.push_back(ch);
            }
        }
        if(mp.find(seg) == mp.end() )
            ans.push_back(seg);
        return ans;
    }
};
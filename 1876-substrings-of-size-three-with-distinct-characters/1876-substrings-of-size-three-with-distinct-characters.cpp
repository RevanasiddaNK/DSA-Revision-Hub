class Solution {
public:

    bool checkGood(int freq[] ){

        for(int i=0; i<26; i++){
            if(freq[i] > 1)   return 0;
        }
        return 1;
    }

    int countGoodSubstrings(string s) {

        if(s.size() < 3)
            return 0;
        
        int freq[26] = {0};
        for(int i=0; i<3; i++){
            freq[s[i]-'a']++;
        }
        int count=0;
        if(checkGood(freq))
            count++;
        for(int i=3; i<s.size(); i++ ){
            freq[s[i-3]-'a']--;
            freq[s[i]-'a']++;
            if(checkGood(freq))
                count++;
        }
        return count;
    }
};
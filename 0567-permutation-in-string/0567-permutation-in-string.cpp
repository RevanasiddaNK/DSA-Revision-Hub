class Solution {
public:

    bool checkFreq(int s2freq[], int s1freq[]){
        for(int i=0; i<26; i++){
            if(s2freq[i] != s1freq[i])
                return 0;
        }
        return 1;
    }

    bool checkInclusion(string s1, string s2) {
        int s1freq[26] = {0};
        for(char c : s1){
            s1freq[c-'a']++;
        }

        int k = s1.size();
        int n = s2.size();
        if(k > n)
            return 0;

        int s2freq[26] = {0};
        for(int i=0; i<k; i++)
            s2freq[s2[i]-'a']++;

        if( checkFreq(s2freq, s1freq) ){
           return 1;
        }

        for(int i=k; i<n; i++){
            s2freq[s2[ i-k ]-'a']--;
            s2freq[s2[i]-'a']++;
            if( checkFreq(s2freq, s1freq) )
                return 1;
        
        }
        return 0;
    }
};
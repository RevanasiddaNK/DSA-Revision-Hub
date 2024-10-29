class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
       
        vector<int>alphaCount(26, 0);
        const int MOD = 1000000007;
        // Initialising alphaCount array
        for(char c : s){
            int i = c-'a';
            alphaCount[i]++;
        }

        for(int i=0; i<t; i++){
            for(int j=1; j<26; j++){
                swap(alphaCount[0] , alphaCount[j]);
            }
            alphaCount[1] = ( alphaCount[1] + alphaCount[0] ) % MOD ;
        }

        int l = 0;
        for(int i=0; i<26; i++)
            l = ( l + alphaCount[i] ) % MOD ;

        return l;
    }
};

        /*
        TC : O(N)
        SC : O(1)
        */
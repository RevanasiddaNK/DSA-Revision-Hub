class Solution {
public:

    int lengthCommonPrefix(string s1, string s2){
        int len =0;
        int n = min( s1.size(), s2.size() );
        for(int i=0; i<n; i++){
            if(s1[i] != s2[i])
                break;
            len++;
        }
        return len;
    }

    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size();
        if(n < 2)   return {0};
        vector<int>ans(n,0);
        vector<int>pairLen(n, 0);
        vector<int>prefix(n - 1, 0);
        vector<int>suffix(n - 1, 0);

        for(int i=0; i<n-1; i++){
           pairLen[i] = lengthCommonPrefix(words[i], words[i+1]);
        }

        int maxLen = 0;
       
        for(int i=0; i<n-1; i++){
            maxLen = max( maxLen, pairLen[i]);
            prefix[i] = maxLen;
        }

        maxLen = 0;
    
        for(int i=n-2; i>=0; i--){
            maxLen = max( maxLen, pairLen[i]);
            suffix[i] = maxLen;
        }
        
       for (int i = 0; i < n; i++) {
            int best = 0;
            if (i > 0 && i < n - 1) {
                int mid = lengthCommonPrefix(words[i - 1], words[i + 1]);
                int left = (i - 2 >= 0) ? prefix[i - 2] : 0;
                int right = (i + 1 < n - 1) ? suffix[i + 1] : 0;
                best = max({left, mid, right});
            }else if (i-2 >= 0) {
                best =  prefix[i - 2];
            } else if (i + 1 < n - 1) {
                best = suffix[i + 1];
            }
            ans[i] = best;
        }

        return ans;
    }
};
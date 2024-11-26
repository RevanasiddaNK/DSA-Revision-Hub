class Solution {
public:

    #define base 256
    #define mod 257

    // using Search Pattern (Rabin-Karp Algorithm)

    int strStr(string text , string pattern) {

        int m = pattern.size(); // or pattern.length();
        int n = text.size();
            
        int h = 1; // h = d^(m-1)
            
        for(int i=1; i<m;i++){
             h = (h*base) % mod;
        }
            
            int p=0,t=0;
            for(int i=0; i<m; i++){
                p = ( (p*base)+pattern[i] )%mod;
                t = ( (t*base)+text[i] )%mod;
            }

            for(int i=0; i<=n-m; i++){
                
                if(p == t){
                    
                    int j=0;
                    for( ; j<m && i+j < n; j++ ){
                        if(text[i+j] != pattern[j])
                            break;
                    }
                    if(j == m)
                        return i;
                }
                
                if( i < n-m ){ 
                    t = (base * (t - text[i] * h) + text[i + m]) % mod;
                }
                
                if(t < 0)
                    t = t + mod;
                
            }
            
            return -1;
    }
};
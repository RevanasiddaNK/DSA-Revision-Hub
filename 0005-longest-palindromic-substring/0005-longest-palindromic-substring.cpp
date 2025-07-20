class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int len = 0;
        int n = s.size();
        int l,r;
        for(int i=0; i<n; i++){
            //odd size l=r=i
            l=r=i;

            while(l >= 0 && r < n && s[l] == s[r]){
                if(len < r-l+1){
                    len = r-l+1;
                    ans = s.substr(l, len);
                }
                l--;
                r++;
            }

            //even size l=i, r=i+1
            l=i;
            r=i+1;

            while(l >= 0 && r < n && s[l] == s[r]){
                if(len < r-l+1){
                    len = r-l+1;
                    ans =  s.substr(l, len);
                }
                l--;
                r++;
            }
        }
        return ans;
    }
};
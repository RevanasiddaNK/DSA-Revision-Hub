class Solution {
public:
    string minWindow(string s, string t) {

        if(t == "" || s=="")
            return "";

        vector<int>countT(256,0);
        vector<int>countS(256,0);

        int need = 0;
        for(char ch : t){
            int i =ch-'A';
            if(countT[i] == 0)
                need++;
            countT[i]++;
        }

        int have=0;
        int l=0,r=0, minLength = INT_MAX;
        int ans[2] = {-1,-1};
        for( ; r<s.size(); r++){

            int i = s[r]-'A';
            countS[i]++;

            if( countT[i] != 0 && countT[i] == countS[i] ){
                have++;
            }

            while(have == need){

                if( r-l+1 < minLength ){
                    ans[0] = l;
                    ans[1] = r;
                    minLength = r-l+1;
                }

                countS[ s[l] - 'A' ]--;

                if(countT[i] != 0 && countT[ s[l] - 'A' ] >  countS[ s[l] - 'A' ] )
                    have--;
                
                l++;

            }

        }

        if(ans[0] == -1 || ans[1] == -1)
            return "";

        return s.substr(ans[0] , minLength);
    }
};
/*
Time Complexity: O(N)
Space Complexity: O(1)
*/
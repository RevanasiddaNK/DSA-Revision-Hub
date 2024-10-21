class Solution {
public:

    bool isPalin(string str, int st, int e){
        while(st <= e){
            if(str[st++] != str[e--]){
                return 0;
            }
        }
        return 1;
    }

    bool validPalindrome(string s) {
        int n = s.size();

        int st=0, e=n-1;
        while(st <= e){
            if(s[st] != s[e]){

                bool remSchar = isPalin(s,st+1,e);
                bool remEchar = isPalin(s,st,e-1);

                if(! (remSchar || remEchar) ){
                    return 0;
                }
                else{
                    return 1;
                }

            }
            else{
               st++;
                e--;
            }
        }
        return 1;
    }
};
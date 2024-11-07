class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());  // Step 1: Reverse the entire string.
        int i = 0, n = s.size(), l=0, r=0;
        while(i < n){

            while(i < n && s[i] != ' '){
                s[r++] = s[i++];
            }

            if(l < r){
             
                reverse(s.begin()+l, s.begin()+r);
                s[r] = ' ';
                r++;
                l = r;
            }
            i++;
        }
        s.resize(r-1);
        return s;
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

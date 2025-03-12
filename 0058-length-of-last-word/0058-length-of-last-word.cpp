class Solution {
public:
    int lengthOfLastWord(string st) {
        int e=st.size()-1;
        while(e >= 0 && st[e] == ' '){
            e--;
        }
        
        int s = e-1;
        while(s >= 0 && st[s] != ' ')
            s--;

        return e-s;
    }
};
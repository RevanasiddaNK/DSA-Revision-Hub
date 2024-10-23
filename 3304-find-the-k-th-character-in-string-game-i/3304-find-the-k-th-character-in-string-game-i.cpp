class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while(s.size() <= k){
            int n = s.size(), i = 0;
            while(i < n){
                char ch = s[i++];
                int j = ch - 'a'+1;
                if(j < 26)
                    s.push_back(char(j+'a'));
                else
                    s.push_back('a');
            }
        
        }
        return s[k-1];
    }
};

/*
TC :  O(N^2)
SC : O(N)
*/
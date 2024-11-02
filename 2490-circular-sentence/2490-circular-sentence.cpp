class Solution {
public:
    bool isCircularSentence(string sentence) {

        int n = sentence.size();
        for(int i=0; i<n; i++){
            if(sentence[i] == ' ' && i - 1 >= 0 && i+1 < n){
                if(sentence[i-1] != sentence[i+1])
                    return 0;
            }
        }

        if(sentence[0] == sentence[n-1])
            return 1;
        else
            return 0;
    }
};

/*

TC : O(N)
SC : O(1)

*/
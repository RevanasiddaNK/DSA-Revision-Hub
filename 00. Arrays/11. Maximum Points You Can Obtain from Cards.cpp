class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();
  
       
        int leftPrefixSum = 0;
        int rightPrefixSum = 0;
        
        for(int i=n-1; i>=n-k; i--)
            rightPrefixSum += cardPoints[i];

      
        int ans = 0;

        for(int i=0; i<=k; i++){
            ans = max(ans, leftPrefixSum + rightPrefixSum );
            leftPrefixSum += cardPoints[i];
            if(i != k)
                rightPrefixSum  -= cardPoints[n-k+i];
       }
       return ans;
    }
};
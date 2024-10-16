class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
     int n = cardPoints.size();
     int e=n-k;
     int s=0;
     int sum = 0;
     for(int i=k; i>0; i--){
     	sum += cardPoints[n-i];
     }
     int profit=sum;
     int i=0,j=n-k;
     while(i<=k && j<n){
     
     	sum +=  cardPoints[i++];
     	sum -=  cardPoints[j++];
     	profit = max(profit, sum);
     	
     }
     return profit;
        
}
};
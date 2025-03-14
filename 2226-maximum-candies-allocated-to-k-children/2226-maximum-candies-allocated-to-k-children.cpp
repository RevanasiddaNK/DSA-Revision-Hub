class Solution {
public:

    bool canDist(vector<int>candies, long long k, long long m) {
        long long num = 0;
        for(int i=0; i<candies.size(); i++){
            if(m != 0)
                num += candies[i] / m ;
        }
        
        return k <= num || m == 0;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long s=0, e =  accumulate(candies.begin(), candies.end(), 0LL);
        long long ans = -1;
        while(s <= e){
            long long m = s+(e-s)/2;
            if(canDist(candies,k,m)){
                ans = m;
                s = m+1;
            }else{
                e = m-1;
            }
        }
        return ans;
        
    }
};
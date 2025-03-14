class Solution {
public:

     bool canDist(vector<int>quantities, long long k, long long m) {
         int num = 0;
        for (int q : quantities) {
            num += (q + m - 1) / m;  // Equivalent to ceil(q / m) 
            //The mathematical ceiling function ceil(x) rounds a number up to the nearest integer.
            //ceil(5 / 2) = ceil(2.5) = 3
            // A store can only be given at most one product type but can be given any amount of it.
            //x represent the maximum number of products given to any store
        }
        return num <= k;  
    }


    int minimizedMaximum(int n, vector<int>& quantities) {
        long long s=1, e =  *max_element(quantities.begin(), quantities.end());
        long long ans = -1;
        while(s <= e){
            long long m = s+(e-s)/2;
            if(canDist(quantities,n,m)){
                ans = m;
                e = m-1;
                
            }else{
                s = m+1;
            }
        }
        return ans;
    }
};
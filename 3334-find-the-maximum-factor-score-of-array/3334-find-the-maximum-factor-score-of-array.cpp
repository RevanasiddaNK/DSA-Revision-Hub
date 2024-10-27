class Solution {
public:

     long long getGCD2Num( long long a, long long b){

        long long n2 = min(a,b);
        long long n1 = max(a,b);

        while(n2 != 0){
            long long d = n1 % n2;
            n1 = n2;
            n2 = d;
        }
        return n1;
    }

    long long getLCM2Num( long long a,  long long b){
        return (a/getGCD2Num(a,b))*b ;
    }

    long long getFactor(int k, int n, vector<int>& nums){
        
        long long gcd = 0, lcm = 1; 

        for(int i=0; i<n; i++){
            if(i != k){
                gcd = gcd == 0 ? nums[i] : getGCD2Num(gcd, nums[i]);
                lcm = getLCM2Num(lcm, nums[i]);
            }
        }
        return gcd*lcm;
    }



    long long maxScore(vector<int>& nums) {
        int n = nums.size();

        if(n == 1){
            return nums[0]*nums[0];
        }

        long long factoreScore = 1;
        for(int i=0; i<=n; i++){
            factoreScore = max(factoreScore, getFactor(i,n,nums) );
        }
        return factoreScore;
    }
};

/*
TC : O(N^2 * log(a+b))
SC : O(1)
*/
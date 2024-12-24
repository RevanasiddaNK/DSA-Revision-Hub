class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //observation based sol using prefix, suffix 
        int res = INT_MIN;
        int pref=1, suf=1;
        int n = nums.size();
        for(int i=0; i<nums.size(); i++){
        
            if(pref == 0)
                pref = 1;
            if(suf == 0)
                suf = 1;

            pref *= nums[i];
            suf *= nums[n-i-1];
            res = max(res,  max(pref,suf));
        }


        return res;
    }
};
/*
TC : O(N)
SC : O(1)
*/
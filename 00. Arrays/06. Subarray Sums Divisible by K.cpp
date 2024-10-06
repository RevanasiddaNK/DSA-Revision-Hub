class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n =nums.size();
        int count = 0;
        unordered_map<int,int>mp;
        mp[0] = 1;
        int psum =0;
        for(int i=0; i<n; i++){

            psum += nums[i];
            int r = psum % k;
            if (r < 0) r += k;

            if(  mp.find(r) != mp.end() ){
             
                count += mp[r];
            }
       

            if( mp.find( r ) != mp.end() )
                mp[ r ]++;
            else
                mp[r] = 1;
      
        }
        return count;

    }
};
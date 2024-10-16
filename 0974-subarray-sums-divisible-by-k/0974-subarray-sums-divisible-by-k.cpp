class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int count = 0;
        unordered_map<int,int>mp;
        int p=0;
        mp[0] = 1;
        for(int i=0; i<n; i++){
           p += nums[i];
           int r = p%k;
           if(r < 0)
            r += k;

            if(mp.find(r) != mp.end()){
                count += mp[r];
                 mp[r]++;
            }
            else{
                mp[r] = 1;
            }
        }
        return count;
    }
};
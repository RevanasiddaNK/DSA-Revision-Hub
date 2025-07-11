class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        if(nums.size() == 1 && k == 0 && nums[0] != 0)
            return 0;

        int ps=0;
        unordered_map<int,int>mp;
        mp[0] = 1;
        int count = 0;
        for(int i : nums){
            ps += i;
            count += mp[ps-k];
            mp[ps]++;
        }
        return count;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int c = target - nums[i];
            if(mp.find(c) != mp.end()){
                ans.push_back(mp[c]);
                ans.push_back(i);
                return ans;
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};
/*

    TC : O(N)
    SC : O(N)

*/
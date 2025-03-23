class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int>mp;
        for(int i=0;i<nums.size(); i++){

            if(mp.find(target-nums[i]) != mp.end()){
            
                return vector<int>{i,mp[target-nums[i]] };
            }
            mp[nums[i]] = i;
        }
        return vector<int>{};
    }
};
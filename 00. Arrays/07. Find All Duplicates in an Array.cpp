class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;

        for(int i=0; i<nums.size() ; i++ ){
            int j = abs(nums[i]);
            if(nums[j-1] < 0)
                ans.push_back(j);
            else
                nums[j-1] *= -1;
        };

        return ans;
    }
};
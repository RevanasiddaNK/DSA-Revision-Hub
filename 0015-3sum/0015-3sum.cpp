class Solution {
public:
    vector<vector<int>> threeSum(vector<int>&nums) {
        int n=nums.size();
        vector<vector<int>>ans;

        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){

            if(i != 0 && nums[i] == nums[i-1])
                continue;

            int s=i+1, e=n-1;

            while(s < e){
                double sum = nums[i] + nums[s] + nums[e];

                if(sum == 0){
                    ans.push_back({nums[i], nums[s], nums[e] });

                    while(s < e && nums[s] == nums[s+1])
                        s++;

                    while(s < e && nums[e] == nums[e-1])
                        e--;
                    
                    s++;
                    e--;
                }
                else if(sum < 0)
                    s++;
                else
                    e--;
            }

           
            
        }
        return ans;
    }
};
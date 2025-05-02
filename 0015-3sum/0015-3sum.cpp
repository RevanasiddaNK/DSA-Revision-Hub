class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0; i<n; i++){

            if(i>0 && nums[i] == nums[i-1])
                continue;
            int s=i+1,e=n-1;
            while(s < e){
                double sum = nums[s] + nums[e] + nums[i];
                if(sum == 0){
                    ans.push_back({ nums[i], nums[s], nums[e]  });
                    int st = nums[s], ed = nums[e];
                    s++;
                    e--;
                    while(s < e && st == nums[s])
                        s++;
                    while(s < e && ed == nums[e])
                        e--;
                    

                }else if(sum < 0){
                    s++;
                }else{
                    e--;
                }
            }
        }
        return ans;
    }
};
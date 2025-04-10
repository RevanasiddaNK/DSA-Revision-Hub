class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        int n = nums.size();
        for(int i=0; i<n; i++ ){
            if(i>0 && nums[i] == nums[i-1])
                    continue;
            for(int j=i+1; j<n; j++){
                if (j > i + 1 && nums[j] == nums[j - 1]) 
                    continue;
                int s=j+1, e=n-1;
                while(s < e){
                    long long sum = nums[i]+nums[j]+nums[s]+nums[e];
                    if(sum == target){
                        ans.push_back({nums[i],nums[j],nums[s],nums[e]});
                        
                        int st = nums[s++];
                        int ed = nums[e--];

                        while(s<e && st == nums[s])
                            s++;

    
                        while(s<e && ed == nums[e])
                            e--;
                        
                    }else if(sum <= target)
                        s++;
                    else
                        e--;
                } 
            }
        }
        return ans;
    }
};
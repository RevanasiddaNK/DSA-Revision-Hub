class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i=0; i<n; i++){

           if(i > 0 && nums[i] == nums[i-1]) continue;
          

            for(int j=i+1; j<n; j++){

               if(j > i + 1 && nums[j] == nums[j-1]) continue;
              
                int s=j+1, e = n-1;
                while(s < e){
                    double sum = nums[i]/4.0 + nums[j] /4.0+ nums[s]/4.0 + nums[e]/4.0;
                    if(target/4.00 == sum){
                        ans.push_back({nums[i] , nums[j] , nums[s] , nums[e]});

                        int k = nums[s];
                        while(s<e && k == nums[s]) 
                            s++;
                        k = nums[e];
                        while(s<e && nums[e] == k)
                            e--;

                    }
                    else if(sum < target/4.00)
                        s++;
                    else
                        e--;
                }
               
            }
        
        }
        return ans;
    }
};
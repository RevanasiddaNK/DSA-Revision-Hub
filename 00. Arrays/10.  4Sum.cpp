class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-3; i++){

            if(i>0 && nums[i] == nums[i-1])
                continue;

            for(int j=i+1; j<n-2; j++){

                if( j>1+i && nums[j] == nums[j-1] )
                    continue;


                int s = j+1, e=n-1;

                while(s < e ){
                    double t = target / 4.00;
                    double sum = nums[i]/4.0 + nums[j]/4.0 + nums[s]/4.0 + nums[e]/4.0;
/*
                    int t = target;
                    int sum = nums[i] + nums[j] + nums[s] + nums[e];
*/
                    if(sum == t ){
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[s]);
                        temp.push_back(nums[e]);

                        ans.push_back(temp);

                        while(s < e && nums[s] == nums[s+1])
                            s++;
                        
                        while( s < e && nums[e] == nums[e-1] )
                            e--;

                        s++;
                        e--;

                    }
                    else if(sum < t)
                        s++;
                    else
                        e--;

                }
            }
        }
        return ans;
    }
};
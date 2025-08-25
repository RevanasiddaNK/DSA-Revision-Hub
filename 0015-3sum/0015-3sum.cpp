class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        for(int i=0; i<n; i++){

            int s=i+1, e=n-1;
            if( i>0 && nums[i] == nums[i-1] )
                continue;

            while(s < e){

                int sum = nums[i] + nums[s] + nums[e];

                if(sum == 0){

                    ans.push_back( {nums[i], nums[s], nums[e]  } );
                    int sEl = nums[s], eEl = nums[e];
                    s++;
                    e--;
                    while( s<e && nums[s] == sEl ){
                        s++;
                    }

                    while( s<e && nums[e] == eEl ){
                        e--;
                    }

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
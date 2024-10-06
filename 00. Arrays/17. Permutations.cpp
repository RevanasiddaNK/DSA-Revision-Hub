class Solution {
public:

     void efficientBacktrackSol( vector<vector<int>>&pm, int n, vector<int>&nums) {
        if(n == nums.size()-1 ){
            pm.push_back(nums);
            return;
        }
            
        
   

        for(int i=n; i<nums.size(); i++){
            swap(nums[i],nums[n]);
            efficientBacktrackSol(pm, n+1, nums);
            //Backtrack
            swap(nums[i],nums[n]);
      
        }

    }


    vector<vector<int>> permute( vector<int>& nums) {

        int n=nums.size();
        vector<vector<int>>pm;
        //pm.push_back(nums);
        //recSol(pm,n-1);

        efficientBacktrackSol(pm, 0, nums);

        return pm;
    }
};
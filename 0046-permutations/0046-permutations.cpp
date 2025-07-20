class Solution {
public:

    void findPermutations( vector<int>&nums, vector<int>&perm, vector<int>freq,  vector<vector<int>>&ans,int n){
        
        if(perm.size() == n){
            ans.push_back(perm);
            return;
        }
        
        for(int i=0; i<n; i++){
            if( freq[i] == 0 ){
                perm.push_back(nums[i]);
                freq[i] = 1;
                findPermutations( nums, perm, freq, ans, n);
                freq[i] = 0;
                perm.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>perm;
        int n=nums.size();
        vector<int>freq(n,0);
        findPermutations( nums, perm, freq, ans, n);
        return ans;
    }
};
class Solution {
public:
void solve(int i, vector<int>&candidates, int target, vector<int>temp, vector<vector<int>>&ans ){

    if(target == 0){
        ans.push_back(temp);
        return;
    }

     if(i >= candidates.size() || target < 0)
        return;
    
    solve(i+1,candidates, target, temp, ans);

    int sum = 0;
    while(sum+candidates[i] <= target){
        temp.push_back(candidates[i]);
        sum += candidates[i];
        solve(i+1,candidates, target-sum, temp, ans);
    }

}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>temp;
        solve(0, candidates, target, temp, ans);
        return ans;
    }
    
};

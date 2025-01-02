class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int totalMax =  *max_element(nums.begin(), nums.end());
        int maxi = 1, mini = 1;
        for(int i=0; i<nums.size(); i++){
            int tempMini =  mini;   
           mini = min({nums[i], maxi*nums[i], mini*nums[i]});
           maxi = max({nums[i], maxi*nums[i], tempMini*nums[i]});
           totalMax = max( totalMax, maxi);
        }
        return totalMax;
    }
};
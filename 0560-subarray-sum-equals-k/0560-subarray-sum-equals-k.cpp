class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans =0;
        int n=nums.size();
        unordered_map<int, int>frq;
        frq[0] = 1;
        int sum =0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(frq.find(sum - k) != frq.end()){
                ans += frq[sum-k];
            }

            if(frq.find(sum) == frq.end()){
                frq[sum] = 1;
            }else{
                frq[sum]++;
            }
        }
        return ans;
    }
};
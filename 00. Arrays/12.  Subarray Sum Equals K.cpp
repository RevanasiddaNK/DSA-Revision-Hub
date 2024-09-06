class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefixSum = 0;
        int n = nums.size();
        int count = 0;
        unordered_map<int,int>f;
        f[0] = 1;
        for(int i=0; i<n; i++){
            prefixSum += nums[i];
            if(f.find(prefixSum-k) != f.end()){
                count += f[prefixSum-k];
            }
            

            if(f.find(prefixSum) != f.end())
                f[prefixSum] += 1;
            else
                f[prefixSum] = 1;
        }
        return count;

    }
};
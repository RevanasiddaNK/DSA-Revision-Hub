class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long>ans(k,0);
        long long prod = 1;
        int n = nums.size();

        for(int i=0; i<n; i++){
            prod = 1;
            for(int j=i; j<n; j++){
               prod = (static_cast<__int128>(prod) * nums[j]) % k;
                ans[ prod % k ]++;
            }
        }
        return ans;
    }
};
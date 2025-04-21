class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> ans(k, 0), cnt(k, 0);
        for (int i = 0; i < n; i++) {
            nums[i] %= k;
            vector<long long> nCnt(k, 0);
            nCnt[nums[i]]++;
            for (int x = 0; x < k; x++) {
                nCnt[x * nums[i] % k] += cnt[x];
            }
            cnt = nCnt;
            for (int x = 0; x < k; x++) ans[x] += cnt[x];
        }
        return ans;
    }
};
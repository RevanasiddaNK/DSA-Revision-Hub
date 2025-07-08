class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>cntSubArrfrmStart;
        int sum =0;
        cntSubArrfrmStart[0] = 1;
        int prefix = 0;
        int count = 0;
        for(int num : nums){
            prefix += num;
            sum += num;
            if(cntSubArrfrmStart.find(prefix - k) != cntSubArrfrmStart.end()){
                count += cntSubArrfrmStart[prefix - k ];
            }
            cntSubArrfrmStart[sum]++;
        }
        return count;
    }
};
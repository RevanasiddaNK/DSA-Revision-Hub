class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int s=0,e=0, n=nums.size();
        unordered_map<int,int>fq;
        int sum = 0;
        fq[0] = 1;
       
        int count = 0;
        sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(fq.find(sum-k) != fq.end() ){
                count += fq[sum-k];
            }

            if(fq.find(sum) == fq.end()){
                fq[sum] = 1;
            }
            else
                fq[sum]++;
        }
            
        return count;
    }
};
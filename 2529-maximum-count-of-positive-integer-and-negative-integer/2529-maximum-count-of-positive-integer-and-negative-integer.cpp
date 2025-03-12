class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg=0,pos=0;
        for(int i:nums){
            if(i < 0)
                neg++;
            else if(i > 0)
                pos++;
        }
        return max(pos,neg);
    }
};
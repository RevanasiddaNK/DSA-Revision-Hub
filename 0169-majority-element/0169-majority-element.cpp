class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        //sort(nums.begin(), nums.end());
        //return nums[(n-1)/2];

        int vote = 0, candidate = nums[0];
        for(int i=0; i<n; i++){
            if(vote == 0){
                vote++;
                candidate = nums[i];
            }
            else{
                if(nums[i] == candidate )
                    vote++;
                else
                    vote--;
            }
        }

        int count = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == candidate )
                count++;
        }
        if(count > n/2)
            return candidate ;
        else
            return 0;
    }
};
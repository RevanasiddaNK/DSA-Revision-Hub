class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast=0,slow=0;



        do{
            slow = nums[slow];
            fast = nums[nums[fast]];

        }
        while(fast != slow);

        slow = 0;

        do{
            slow = nums[slow];
            fast = nums[fast];

        }
        while(fast != slow);

        return slow;
      
    }
};
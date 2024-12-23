class Solution {
public:

    bool containsDuplicateUsingSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0; i<n-1; i++ ){
            if(nums[i] == nums[i+1]){
                return 1;
            }
        }
        return 0;
        /*
            TC : O(N*Log(N)) 
            SC : O(1)
        */
    }

    bool containsDuplicateUsingHashMap(vector<int>& nums) {
        unordered_map<int,int>count;
        for(int i : nums){
            if(count.find(i) != count.end()){
                return 1;
            }
            count[i] = 1;
        }
        return 0;
         /*
            TC : O(N) 
            SC : O(N)
        */
    }

    bool containsDuplicate(vector<int>& nums) {
        return containsDuplicateUsingHashMap(nums);
    }
};
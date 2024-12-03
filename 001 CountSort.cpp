class Solution {
public:

    vector<int> countSort(vector<int>&nums, int n) {
        int maxi = nums[0];
        for(int i=0; i<n; i++)
            maxi = max(maxi, nums[i]);
        vector<int>Count(maxi+1,0);
        // count array
        for(int i=0; i<n; i++){
            Count[nums[i]]++;
        }
//Cumutalative sum of count
        for(int i=1; i<maxi+1; i++){
           Count[i] += Count[i-1];
        }

        vector<int>outputArray(n,0);
// cumulative count array will have indices to place element at last position of element value
        for(int i=n-1; i>=0; i--){
            outputArray[ Count[nums[i]] - 1 ] = nums[i];
             Count[nums[i]]--;
        }

        return  outputArray;
    }

    vector<int> sortArray(vector<int>& nums) {
        // count Sort 
        int n = nums.size();
        return countSort(nums,n);
        
    }
};

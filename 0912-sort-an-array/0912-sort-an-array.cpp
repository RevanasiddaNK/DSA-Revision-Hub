class Solution {
public:

    void merge(vector<int>& nums, int s, int m, int e){
        int i=s, j=m+1;
        vector<int>temp;

        while(i <= m && j <= e){
            if(nums[i] < nums[j]){
                temp.push_back(nums[i++]);
            }else{
                temp.push_back(nums[j++]);
            }
        }

        while(i <= m){
            temp.push_back(nums[i++]);
        }

        while(j <= e){
            temp.push_back(nums[j++]);
        }

        i=0;
        for(int i=0; i<=e-s; i++){
            nums[s+i] = temp[i];
        }
    }

    void mergeSort(vector<int>& nums, int s, int e){
        if(s>=e)
            return;
        
        int m = s+(e-s)/2;

        mergeSort(nums, s, m);
        mergeSort(nums, m+1, e);

        merge(nums,s,m,e);

    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums,0,n-1);
        return nums;
    }
};
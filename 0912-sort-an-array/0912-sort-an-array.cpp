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

    int findPivotHoaresPartition(vector<int>& nums, int s, int e){
        int pivot = nums[s];  // Use first element as pivot for Hoare's scheme
        int i = s - 1;
        int j = e + 1;

        while(true) {
            // Move i to the right
            do {
                i++;
            } while(i <= e && nums[i] < pivot);

            // Move j to the left
            do {
                j--;
            } while(j >= s && nums[j] > pivot);

            // If pointers cross, partitioning is done
            if(i >= j) return j;

            swap(nums[i], nums[j]);
        }
    }

    void quickSort(vector<int>& nums, int s, int e){
        if(s >= e){
            return;
        }

        int p = findPivotHoaresPartition(nums, s, e);  // Partition returns the split index

        quickSort(nums, s, p);       // Recur on left part
        quickSort(nums, p + 1, e);   // Recur on right part
    }


    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        //mergeSort(nums,0,n-1);

        quickSort(nums,0,n-1);

        return nums;
    }
};
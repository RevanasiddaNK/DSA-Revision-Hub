class Solution {
public:

    void merge(vector<int>& nums, int s, int m, int e){
        int i = s, j = m + 1;
        vector<int> temp;

        while(i <= m && j <= e){
            if(nums[i] < nums[j]){
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }

        while(i <= m){
            temp.push_back(nums[i++]);
        }

        while(j <= e){
            temp.push_back(nums[j++]);
        }

        for(int k = 0; k < temp.size(); k++){
            nums[s + k] = temp[k];
        }
    }

    void mergeSort(vector<int>& nums, int s, int e){
        if(s >= e) return;

        int m = s + (e - s) / 2;
        mergeSort(nums, s, m);
        mergeSort(nums, m + 1, e);
        merge(nums, s, m, e);
    }

    int findPivotHoaresPartition(vector<int>& nums, int s, int e){
        int pivot = nums[s];
        int i = s - 1, j = e + 1;

        while(true) {
            do { i++; } while(i <= e && nums[i] < pivot);
            do { j--; } while(j >= s && nums[j] > pivot);

            if(i >= j) return j;
            swap(nums[i], nums[j]);
        }
    }

    int LomutoPartition(vector<int>& nums, int s, int e){
        int i = s - 1;
        int pivot = nums[e];
        for(int j = s; j < e; j++){
            if(nums[j] < pivot){
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[e]);
        return i + 1;
    }

    void quickSort(vector<int>& nums, int s, int e){
        if(s >= e) return;

        // Choose either partition scheme (uncomment one of these):

        // --- Lomuto Partition ---
        int p = LomutoPartition(nums, s, e);
        quickSort(nums, s, p - 1);
        quickSort(nums, p + 1, e);

        // --- Hoare Partition (if using) ---
        // int p = findPivotHoaresPartition(nums, s, e);
        // quickSort(nums, s, p);
        // quickSort(nums, p + 1, e);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        // --- Use Merge Sort ---
        // mergeSort(nums, 0, n - 1);

        // --- Use Quick Sort ---
        quickSort(nums, 0, n - 1);

        return nums;
    }
};

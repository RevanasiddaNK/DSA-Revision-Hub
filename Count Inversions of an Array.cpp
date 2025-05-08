class Solution {
  public:
    int merge(vector<int>& nums, int s, int m, int e){
        int i = s, j = m + 1;
        vector<int> temp;
        int cntInv = 0;
        
        while(i <= m && j <= e){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i++]);
            } else {
                cntInv += (m - i + 1);
                temp.push_back(nums[j++]);
            }
        }

        while(i <= m) temp.push_back(nums[i++]);
        while(j <= e) temp.push_back(nums[j++]);

        for(int k = 0; k < temp.size(); k++)
            nums[s + k] = temp[k];

        return cntInv;
    }

    int mergeSort(vector<int>& nums, int s, int e){
        if(s >= e) return 0;

        int m = s + (e - s) / 2;

        int left = mergeSort(nums, s, m);
        int right = mergeSort(nums, m + 1, e);
        int merged = merge(nums, s, m, e);

        return left + right + merged;
    }

    int inversionCount(vector<int> &arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};

class Solution {
public:

    void countReversePairs( vector<int>&nums, int s, int m, int e, int &count ) {
        /*
        for(int i=e; i>m; i--){
            for(int j=s; j<=m; j++){
                if(nums[j]/2.00 > nums[i]  ){
                    count += (m+1-j);
                    break;
                }
            }
        }
        */
        int j= m+1;
        for(int i=s; i<=m; i++){
            while(j<=e && nums[i]/2.00 > nums[j]  )
                j++;
            count += (j-(m+1));
        }
    }

    void mergeSortedArrays( vector<int>&nums, int s, int m, int e ){
        int i=s, j=m+1;
        vector<int>temp;

        while(i <= m && j <= e){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i++]);
            }
            else{
                temp.push_back(nums[j++]);
            }
        }

        while(i <= m){
            temp.push_back(nums[i++]);
        }

        while(j <= e){
            temp.push_back(nums[j++]);
        }

        int k=0;
        for(int i=s; i<=e; i++ ){
            nums[i] = temp[k++];
        }

    }

    void mergeSort(vector<int>& nums, int s, int e, int &count){
        
        if(s < e){

            int m = s+(e-s)/2;
            mergeSort( nums, s, m, count);
            mergeSort( nums, m+1, e, count);
            countReversePairs(nums, s, m, e, count);
            mergeSortedArrays(nums, s, m, e);

        }

    }


    int reversePairs(vector<int>& nums) {
        int count = 0;
        int s=0, e=nums.size()-1;
        mergeSort(nums, s, e, count);
        return count;
    }
};
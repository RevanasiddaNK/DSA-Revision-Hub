class Solution {
public:

     int countPairs(vector<int>& nums,int s, int m, int e){

        int count = 0;
        int j= m+1;
        for(int i=s; i<=m; i++){
            while(j<=e && nums[i]/2.00 > nums[j]  )
                j++;
            count += (j-(m+1));
        }
        return count;
     }

  int  mergeSort(vector<int>& nums,int s, int e){
        if(e-s <= 0)
            return 0;

        int m = (s+e)/2;

        int count = mergeSort(nums, s,m);
        count += mergeSort(nums, m+1 ,e);
        count += countPairs(nums,s, m ,e);
        merge(nums,s,m,e);
        return count;
       
    }

    void merge(vector<int>& nums,int s, int m, int e){

        int i=s;
        int j=m+1;
        vector<int>temp;
        while(i <= m && j <= e){
            if( nums[i] <= nums[j] ){
                temp.push_back(nums[i++]);
            }
            else{
                temp.push_back(nums[j++]);
            }
        }

        while(i<=m){
            temp.push_back(nums[i++]);
        }

        while(j <= e){
            temp.push_back(nums[j++]);
        }

        for(int k=0; k< temp.size(); k++)
            nums[s+k] = temp[k];

    
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
       return mergeSort(nums, 0,n-1);
        
    }
};
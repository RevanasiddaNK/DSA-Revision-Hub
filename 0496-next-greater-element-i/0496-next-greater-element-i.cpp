class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int n1 = nums1.size();
        int n2 = nums2.size();
        for(int i=0;i<n1; i++){
            for(int j=0; j<n2; j++){
                if(nums1[i] == nums2[j]){

                    int k = nums2[j++];
                    while(j < n2 && k >= nums2[j]){
                        j++;
                    }
                    if(j >= n2)
                        ans.push_back(-1);
                    else
                        ans.push_back(nums2[j]);
                }
            }
        }
        return ans;
    }
};
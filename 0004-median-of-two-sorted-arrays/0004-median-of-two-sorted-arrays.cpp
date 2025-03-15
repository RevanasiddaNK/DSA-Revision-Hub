class Solution {
public:
    double solve(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int s = 0, e = n1;

        while (s <= e) {
            int cut1 = s + (e - s) / 2;
            int cut2 = (n1 + n2) / 2 - cut1;

            int l1 = (cut1 > 0) ? nums1[cut1 - 1] : INT_MIN;
            int l2 = (cut2 > 0) ? nums2[cut2 - 1] : INT_MIN;
            int r1 = (cut1 < n1) ? nums1[cut1] : INT_MAX;
            int r2 = (cut2 < n2) ? nums2[cut2] : INT_MAX;

            if (l1 > r2) {
                e = cut1 - 1;
            } 
            else if (l2 > r1) {
                s = cut1 + 1;
            } else {
                if ((n1 + n2) % 2 != 0) {
                    return min(r1, r2);
                } else {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
            }
        }
        return -1;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return solve(nums2, nums1);
        }
        return solve(nums1, nums2);
    }
};

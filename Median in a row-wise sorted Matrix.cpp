class Solution {
  public:
   int calculateSmallEqual(vector<int>& arr, int m) {
    int s = 0, e = arr.size() - 1;
    int ans = arr.size();
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] < m) {
            s = mid + 1;  // Move right to count more elements
        } else {
            ans = mid;
            e = mid - 1;  // Move left
        }
    }
    return ans; // The count of elements ≤ m
}

  
  
    int getNoElementsLeftside(vector<vector<int>> &mat, int m, int r) {
        int ans = 0;
         for(int i=0; i<r; i++){
             ans += calculateSmallEqual(mat[i], m);
         }
         return ans;
     }
  
  
    int median(vector<vector<int>> &mat) {
        int maxi = INT_MIN, mini = INT_MAX;
        int r = mat.size(), c = mat[0].size();
        for(int i=0; i<r; i++){
            maxi = max( maxi, mat[i][c-1] );
            mini = min(mini,mat[i][0] );
            
        }
        int ans = -1;
        int s = mini, e = maxi;
        while(s <= e){
            int m = s+(e-s)/2;
            int leftSide = getNoElementsLeftside(mat,m,r);
            
            if(leftSide <= (r*c)/2){
               ans = m;
                s = m+1;
            }
            else{
                e = m-1;
            }
            
        }
        return ans;
    }
};

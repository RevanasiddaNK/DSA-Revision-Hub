class Solution {
  public:
  
    int solve(vector<int>&a, vector<int>& b,int m, int n, int k){
        int s = max(0, k - n), e = min(k, m);
        while(s <= e){
            int cut1 = s+(e-s)/2;
            int cut2 = k-cut1;
            int l1 = cut1 == 0 ? INT_MIN : a[cut1-1];
            int l2 = cut2 == 0 ? INT_MIN : b[cut2-1];
            int r1 = cut1 == m ? INT_MAX : a[cut1];
            int r2 = cut2 == n ? INT_MAX : b[cut2];
            
            if(l1 > r2){
                e = cut1-1;
            }
            else if(l2 > r1){
                s = cut1+1;
            }else{
                return max(l1,l2);
            }
            
        }
        return -1;
    }
  
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int m = a.size();
        int n = b.size();
        int ans = -1;
        if(m <= n){
            ans = solve(a,b,m,n,k);
        }else{
            ans = solve(b,a,n,m,k);
        }
        return ans;
    }
};

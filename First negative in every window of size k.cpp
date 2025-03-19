class Solution {
  public:
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        queue<int>q;
        vector<int>ans;
        for(int i=0; i<k; i++){
            if(arr[i] <0)
                q.push(arr[i]);
        }
         if(q.empty())
                ans.push_back(0);
            else
                ans.push_back(q.front());
        int n = arr.size();
        for(int i=k; i<n; i++){
            if(arr[i] < 0)
                q.push(arr[i]);
            if(i-k>= 0 && arr[i-k] < 0)
                q.pop();
            if(q.empty())
                ans.push_back(0);
            else
                ans.push_back(q.front());
            
        }
        return ans;
    }
};

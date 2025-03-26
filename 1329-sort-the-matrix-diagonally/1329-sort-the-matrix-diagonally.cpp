class Solution {
public:

    void solve(int i, int j, int m, int n, vector<vector<int>>& mat){
        vector<int>temp;
        int ti=i,tj=j;
        while(ti<m && tj <n){
            temp.push_back(mat[ti++][tj++]);
        }
        sort(temp.begin(), temp.end());
        ti=i,tj=j;
        int index=0;
        while(ti<m && tj<n){
            mat[ti++][tj++] = temp[index++];
        }
    }

    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        int i=0,j=n-1;
        for(int j=n-1; j>=0; j--)
            solve(0,j,m,n,mat);
        for(int i=1; i<m; i++)
            solve(i,0,m,n,mat);
        return mat;
    }
};
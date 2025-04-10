class Solution {
public:
    void rotate(vector<vector<int>>& matrix){
        int m = matrix.size();
        for(int i=0; i<m; i++){
            for(int j=i+1; j<m; j++){
                swap(matrix[i][j], matrix[j][i]);
            }  
        }

        for(int i=0; i<m; i++){
            int s=0,e=m-1;
            while(s <= e){
                 swap(matrix[i][s], matrix[i][e]);
                 s++;
                 e--;
            }
        }
    }
        
};
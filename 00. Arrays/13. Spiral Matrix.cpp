class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>&matrix) {
        int sRow = 0, eRow = matrix.size()-1;
        int sCol = 0, eCol = matrix[0].size()-1;
        int total = (eRow+1) * (eCol+1);
        int count = 0;
        int i=0;
        vector<int>ans;
        while(count < total){

            for(i=sCol; i<=eCol && count < total ; i++){
                ans.push_back( matrix[sRow][i] );
                count++;
            }
            sRow++;


            for(i=sRow; i<=eRow  && count < total; i++){
                ans.push_back( matrix[i][eCol] );
                count++;
            }
            eCol--;

            for(i=eCol; i >= sCol  && count < total; i--){
                ans.push_back( matrix[eRow][i] );
                count++;
            }
            eRow--;

            for(i=eRow; i>=sRow  && count < total; i--){
                ans.push_back( matrix[i][sCol] );
                count++;
            }
            sCol++;

        }

        return ans;
    }
};
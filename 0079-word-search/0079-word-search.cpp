class Solution {
public:

    bool  search(int i, int j, int index,  vector<vector<char>>& board, string word) {

            if(index ==  word.size()-1)
                return 1;
            
            if(i<0 || i>=board.size() || j<0 || j >= board[0].size() )
                return 0;

            char temp = board[i][j];
            board[i][j] = '*';

            bool up=0,down=0,left=0, right=0;
            if(j-1 >= 0 && board[i][j-1] == word[index+1])
                left = search(i, j-1, index+1,  board, word );

            if( j+1 < board[0].size() && board[i][j+1] == word[index+1])
                right = search(i, j+1, index+1,  board, word );

            if(i-1 >= 0 && board[i-1][j] == word[index+1])
                up = search(i-1, j, index+1,  board, word );
            
            if( i+1 < board.size() && board[i+1][j] == word[index+1])
                down = search(i+1, j, index+1,  board, word );
            
            board[i][j] = temp;

          return up || down || left || right;
    }

    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0; i<board.size(); i++ ){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == word[0]){
                    if( search(i, j, 0,  board, word ) )
                        return 1;
                }
            }
        }
        return 0;
    }
};
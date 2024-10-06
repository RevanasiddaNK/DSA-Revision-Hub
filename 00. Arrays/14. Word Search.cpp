class Solution {
public:

    bool recSol( int i, int j, int k, vector<vector<char>>& board, string word, int R, int C, int n ){

        if(k == n)
            return true;

        bool ans = false;


    
        if(i >= R || j >= C || i<0 || j<0 || word[k] != board[i][j])
            return false;
        
        char temp = board[i][j];
        board[i][j] = '*';

        
        bool up=0, down=0, left=0,right=0;

        up = recSol(i-1,j,k+1, board, word, R,C, n);
        down = recSol(i+1,j,k+1, board, word, R,C, n);
        left = recSol(i,j-1,k+1, board, word, R,C, n);   
        right = recSol(i,j+1,k+1, board, word, R,C, n);

        board[i][j] = temp;

        return up||down||left||right;

    }


    bool exist( vector<vector<char>>& board, string word) {

        int R = board.size();
        int C = board[0].size();
        int n = word.size();
        int i=0, j=0, k=0;
        
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                
                if(  recSol(i,j,0, board, word, R,C, n) )
                    return true;
            }
        }
        return false;
    }
};
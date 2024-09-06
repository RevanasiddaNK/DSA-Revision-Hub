class Solution {
public:

    int findNumofliveneighbours( vector<vector<int>>&board, int i,int j, int R, int C){
        int live = 0;

        if( (i-1 >= 0) && ( board[i-1][j] == 1||  board[i-1][j] == 3 ) )
            live++;
        if( ( i-1 >=0 && j-1 >= 0) &&  (board[i-1][j-1]  == 1 || board[i-1][j-1] == 3) )
            live++;
        if( (i-1 >=0 && j+1 < C ) && (board[i-1][j+1] == 1  || board[i-1][j+1] == 3) )
            live++;

        if( (j-1 >= 0) &&   (board[i][j-1] == 1 || board[i][j-1] == 3) )
            live++;

        if( j+1 < C &&   board[i][j+1] )
            live++;

        if( i+1 < R && board[i+1][j])
            live++;
        if( (i+1 < R && j-1 >=0 ) && board[i+1][j-1])
            live++;
        if( (i+1 < R && j+1 <  C) &&  board[i+1][j+1] )
            live++;

        return live;
        
    }

    void gameOfLife( vector<vector<int>>& board) {
        
        int R =  board.size();
        int C =  board[0].size();

        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){

                int live = findNumofliveneighbours(board,i,j,R,C);
                if(board[i][j]){

                    if(live < 2)
                        board[i][j] = 1;
                    else if(live == 2 || live == 3)
                        board[i][j] = 3;
                    else
                        board[i][j] = 1;

                }
                else{
                    if(live == 3)
                        board[i][j] = 2;
                    else
                        board[i][j] = 0;
                }
            }

        }

        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if( board[i][j] == 1 || board[i][j] == 0 )
                    board[i][j] = 0;
                else
                    board[i][j] = 1;  
            }
        }
           
        
    }
};
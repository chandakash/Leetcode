class Solution {
    public void dfs(char[][] board, int i, int j){
        if(i<0 || i>=board.length || j<0 || j>=board[0].length)
            return;
        
        if(board[i][j] == 'O'){
            board[i][j] = '1';
            
            dfs(board,i-1,j);
            dfs(board,i+1,j);
            dfs(board,i,j-1);
            dfs(board,i,j+1);
        }
    }
    public void solve(char[][] board) {
        int row = board.length;
        int column = board[0].length;
        
        // dfs for 1st row & last row
        for(int i=0;i<column;i++){
            dfs(board,0,i);
            dfs(board,row-1,i);
        }
        // dfs for 1st column & last columnn
        for(int i=1;i<row-1;i++){
            dfs(board,i,0);
            dfs(board,i,column-1);
        }
        
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == '1'){
                    board[i][j] = 'O';
                }
            }
        }
    }
    
}
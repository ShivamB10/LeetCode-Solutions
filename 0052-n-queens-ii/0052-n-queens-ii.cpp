class Solution {
public:
    bool validMove(vector<vector<string>>& board, int n, int row, int col){

        for(int temp_row = 0; temp_row < row; temp_row++){
            if(board[temp_row][col] == "Q"){
                return false;
            }    
        }

        for(int temp_row = row, temp_col = col; temp_row>= 0 && temp_col >= 0; temp_row--, temp_col--){
            if(board[temp_row][temp_col] == "Q"){
                return false;
            }
        }

        for(int temp_row = row, temp_col = col; temp_row >= 0 && temp_col < n; temp_row--, temp_col++) {
            if(board[temp_row][temp_col] == "Q") {
                return false;
            }
        }

        return true;
    }

    void solve(int& count,vector<vector<string>>& board, int n, int row){
        if(row == n){
            count++;
            return;
        }

        for(int col = 0; col < n; col++){
            if(validMove(board, n, row, col)){
                board[row][col] = "Q";
                solve(count, board, n,row+1);
                board[row][col] = "-";
            }
        }
    }
    int totalNQueens(int n) {
        int count = 0;
        vector<vector<string>> board(n, vector<string>(n, "-"));
        solve(count, board, n, 0);
        return count;
    }
};
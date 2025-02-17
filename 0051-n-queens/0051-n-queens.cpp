class Solution {
public:
    bool validMove(vector<string>& board, int n, int row, int col){
        for(int temp_row = 0; temp_row < row; temp_row++){
            if(board[temp_row][col] == 'Q') return false;
        }

        for(int temp_row = row, temp_col = col; temp_row>= 0 && temp_col >= 0; temp_row--, temp_col--){
            if(board[temp_row][temp_col] == 'Q'){
                return false;
            }
        }

        for(int temp_row = row, temp_col = col; temp_row >= 0 && temp_col < n; temp_row--, temp_col++) {
            if(board[temp_row][temp_col] == 'Q') {
                return false;
            }
        }
        
        return true;

    }
    void solve(vector<vector<string>>& solutions, vector<string>& board, int n, int row){
        if(row == n){
            solutions.push_back(board);
            return;
        }
        for(int col = 0; col < n; col++){
            if(validMove(board, n, row, col)){
                board[row][col] = 'Q';
                solve(solutions, board, n, row+1);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> board (n, string(n, '.'));
        solve(solutions, board, n, 0);
        return solutions; 
    }
};
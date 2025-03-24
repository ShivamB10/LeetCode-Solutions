class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //row check and column check

        for(int i = 0; i < board.size(); i++){
            unordered_set<char> check_row;
            for(int j = 0; j < board.size(); j++){
                if(board[i][j]!= '.' && check_row.find(board[i][j]) != check_row.end()){
                    return false;
                }

                check_row.insert(board[i][j]);
            }
        }

        for(int col = 0; col < board.size(); col++){
            unordered_set<char> check_col;
            for(int row = 0; row < board.size(); row++){
                if(board[row][col] != '.' && check_col.find(board[row][col]) != check_col.end()){
                    return false;
                }
                check_col.insert(board[row][col]);
            }

        }

        vector<unordered_set<char>> check_box(9);
        for(int k = 0; k < board.size(); k++){
           for(int l = 0; l < board.size(); l++){
            int loc = (k/3)*3 + (l/3);
            if(board[k][l] != '.'  && check_box[loc].find(board[k][l]) != check_box[loc].end()){
                return false;
            }
            check_box[loc].insert(board[k][l]);
           }

        }

    return true;
    
    }
};
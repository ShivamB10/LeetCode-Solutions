class Solution {
public:
    bool check(int row, int col, int count, vector<vector<char>>& board, string word){
        if(word.size() == count){
            return true;
        }
        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size() ||board[row][col] != word[count]){
            return false;
        }

        char temp = board[row][col];
        board[row][col] = ' ';

        bool ans = check(row+1, col, count+1, board,word)|| check(row, col+1,count+1, board,word)||
                   check(row-1, col, count+1, board,word) || check(row, col-1, count+1, board, word);
        
        board[row][col] = temp;
        return ans;



    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int row = 0; row < board.size(); row++){
            for(int col = 0; col < board[0].size(); col++){
                if(board[row][col] == word[0] && check(row,col,0,board,word)){
                    return true;
                }
            }
        }

        return false;
    }
};
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int row = 0; row < matrix.size(); row++){
            for(int col = row + 1; col < matrix.size(); col++){
                swap(matrix[row][col], matrix[col][row]);
            }
        }


        int first_col = 0;
        int last_col = matrix.size()-1;

        while(first_col<last_col){
            for(int rows = 0; rows < matrix.size(); rows++){
                swap(matrix[rows][first_col], matrix[rows][last_col]);
            }
            first_col++;
            last_col--;
        }

    }
};
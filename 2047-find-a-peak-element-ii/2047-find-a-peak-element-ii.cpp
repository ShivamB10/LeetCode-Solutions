class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int start = 0;
        int end = mat[0].size()-1;

        while(start <= end){
            int mid = start + (end - start)/2;

            int max_row = 0;
            for(int row = 0 ; row < mat.size(); row++){
                if(mat[max_row][mid] < mat[row][mid]){
                    max_row =  row;
                }
            }

            int left_row = (mid - 1 >= 0) ? mat[max_row][mid-1] : -1;
            int right_row = (mid+1 < mat[0].size()) ? mat[max_row][mid+1] : -1;


            if(mat[max_row][mid] > max(left_row,right_row)){
                return {max_row,mid};
            }

            else if(left_row > right_row && left_row > mat[max_row][mid]){
                end = mid - 1;
            }

            else if(left_row < right_row && right_row > mat[max_row][mid]){
                start = mid+1;
            }
        }


        return {-1,-1}; 
    }
};
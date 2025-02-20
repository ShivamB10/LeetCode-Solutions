class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();

        int start = 0;
        int end = r*c -1;

        while(start <= end){
            int mid = start + (end - start)/2;
            int mid_val = matrix[mid/c][mid%c];

            if(mid_val == target){
                return true;
            }

            else if(mid_val < target){
                start = mid + 1;
            }

            else if(mid_val > target){
                end = mid - 1;
            }
 
        }

        return false;
    }
};
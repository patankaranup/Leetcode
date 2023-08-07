class Solution1 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        int j = m*n - 1;

        while(i<=j){
            int mid_idx = i + (j-i)/2;
            int matrix_row = mid_idx/n;
            int matrix_col = mid_idx%n;
            if(matrix[matrix_row][matrix_col] > target){
                j = mid_idx-1;
            } else if(matrix[matrix_row][matrix_col] < target){
                i = mid_idx+1;
            } else {
                return true;
            }
        }
        return false;
    }
};
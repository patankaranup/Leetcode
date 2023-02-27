class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose the matrix this will change the rows to columns and 
columns to row 
        for (int i=0; i<matrix.size(); i++){
            for(int j=0; j<i; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        int n = matrix.size() - 1;
        // and now we can reverse the row 
        for(int i=0;i<matrix.size(); i++){
            for(int j=0; j<=n/2; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n-j];
                matrix[i][n-j] = temp;
            }
        }
        
    }
};

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstRowHasZero = false;
        bool firstColHasZero = false;

        // check if first row and first column have zeros
        for(int j=0; j<n; j++){
            if(matrix[0][j] == 0){
                firstRowHasZero = true;
                break;
            }
        }
        for(int i=0; i<m; i++){
            if(matrix[i][0] == 0){
                firstColHasZero = true;
                break;
            }
        }

        // mark rows and columns containing zeros using first row and 
first column as flags
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // set zeros in marked rows and columns
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        // set zeros in first row and first column if necessary
        if(firstRowHasZero){
            for(int j=0; j<n; j++){
                matrix[0][j] = 0;
            }
        }
        if(firstColHasZero){
            for(int i=0; i<m; i++){
                matrix[i][0] = 0;
            }
        }
    }
};


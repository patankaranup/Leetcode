class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int res = 0;
        // for rows i 
        for(int i=0; i<m; i++){
            // for cols j 
            for(int j=0; j<n; j++){
                if(mat[i][j] == 1){
                    // iterate over row and find is there any other 0 present
                    int numRows = 0;
                    int numCols = 0;
                    for(int row = 0; row<m; row++){
                        if(mat[row][j]){
                            numRows++;
                        }
                    }
                    // iterate over col and find is there any other 0 present
                    for(int col = 0; col<n; col++){
                        if(mat[i][col]){
                            numCols++;
                        }
                    }
                    if(numRows==1 && numCols==1){
                        res++;
                    }
                }
            }
        }
        return res;
    }
};
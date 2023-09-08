class Solution1 {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        for(int row=0; row<numRows; row++){
            result[row] = vector<int>(row+1,1);
            for(int col=1; col<row; col++){
                result[row][col] = result[row-1][col-1] + result[row-1][col];
            }
        }
        return result;
    }
};
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // make a vector of vector of size n
        vector<vector<int>> v(numRows);
        for(int i=0; i<numRows; i++){
            // set the size of first row to the  i+1 
            v[i].resize(i+1);
            // set the first col to 1 
            v[i][0] = 1;
            // set the last col to 1 
            v[i][i] = 1;
            // now inner loop will feel the values to previos two sums
            for(int j=1; j<i; j++){
                v[i][j] = v[i-1][j] + v[i-1][j-1];
            }
        }
        return v;
    }
};

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> onesRow(m,0);
        vector<int> onesCol(n,0);
        vector<vector<int>> diff(m, vector<int>(n));

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]) {
                    onesRow[i]++;
                    onesCol[j]++;
                }
            }
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int orow = onesRow[i];
                int ocol = onesCol[j];
                int zrow = m - orow;
                int zcol = n - ocol;
                diff[i][j] = orow + ocol - zrow - zcol;
            }
        }

        return diff;
    }
};
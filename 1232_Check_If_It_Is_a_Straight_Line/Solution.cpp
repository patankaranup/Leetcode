class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        int d_y = coordinates[1][1] - coordinates[0][1]; // y2 - y1
        int d_x = coordinates[1][0] - coordinates[0][0]; // x2 - x1

        for(int i=2; i<n; i++){
            int dy_i = coordinates[i][1] - coordinates[0][1]; // y2 - y1
            int dx_i = coordinates[i][0] - coordinates[0][0]; // x2 - x1

            if(dy_i * d_x != d_y * dx_i){
                return false;
            }
        }
        return true;

    }
};

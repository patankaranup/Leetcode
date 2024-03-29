class Solution {
public:
    double memo[101][101];
    double solve(int poured, int i, int j){
        if(i<0 || j<0 || i<j){
            return 0.0;
        }
        // top glass 
        if(i==0 && j==0){
            return poured;
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        double upper_left = (solve(poured,i-1, j-1) - 1)/2.0;
        double upper_right = (solve(poured,i-1, j) - 1)/2.0;

        if(upper_left < 0){
            upper_left = 0.0;
        }
        if(upper_right < 0){
            upper_right = 0.0;
        }
        return memo[i][j] = upper_left + upper_right;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        for(int i=0; i<101; i++){
            for(int j=0; j<101; j++){
                memo[i][j] = -1;
            }
        }
        return min(1.0, solve(poured,query_row,query_glass));
    }
};
class Solution1 {
public:
    int memo[21][21];
    // difference of score 
    int solve(vector<int>& nums, int i, int j){
        if(i>j){
            return 0;
        }
        if(i==j){
            return nums[i];
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        int take_i = nums[i] - solve(nums,i+1,j);
        int take_j = nums[j] - solve(nums,i,j-1);

        return memo[i][j] = max(take_i,take_j);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        memset(memo,-1,sizeof(memo));
        return solve(nums,0,n-1) >= 0;
    }
};
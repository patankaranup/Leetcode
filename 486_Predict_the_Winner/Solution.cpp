class Solution {
public:
    int memo[21][21];
    int solve(int i,int j,vector<int>& nums){
        if(i>j){
            return 0;
        }
        if(i==j){
            return nums[i];
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        // we can take ith or jth element we will play optimally 
        // similarly we should except worst from the oponent that is the min answer 
        // int the min we are taking the min value left for us after the opponents turn
        // for understanding dry run any test case 
        int take_i = nums[i] + min(solve(i+2,j,nums),solve(i+1,j-1,nums));
        int take_j = nums[j] + min(solve(i,j-2,nums),solve(i+1,j-1,nums));

        return memo[i][j] = max(take_i,take_j);
    }
    bool PredictTheWinner(vector<int>& nums) {
        memset(memo,-1,sizeof(memo));
        int n = nums.size();
        int total_score = accumulate(begin(nums),end(nums),0);
        int p1_score = solve(0,n-1,nums);
        int p2_score = total_score - p1_score;

        return p1_score >= p2_score;
    }
};
class Solution {
public:
    int n;
    int memo[301][11];
    int solve(vector<int>& jobDifficulty, int d, int idx){
        if(memo[idx][d] != -1){
            return memo[idx][d];
        }
        // there is only one day left to complete the job so interate over the job and return the max one
        if(d == 1){
            int max_diff_job_on_last_day = INT_MIN;
            for(int i=idx; i<n; i++) {
                max_diff_job_on_last_day = max(max_diff_job_on_last_day,jobDifficulty[i]);
            }
            return memo[idx][d]= max_diff_job_on_last_day;
        }
        int ans = INT_MAX;
        int curr_max_diff = INT_MIN;

        // try to do for all i on the sub-array till n-d 
        for(int i = idx; i <= n-d; i++){
            curr_max_diff = max(curr_max_diff,jobDifficulty[i]);
            ans = min(ans, curr_max_diff + solve(jobDifficulty,d-1,i+1)); 
        }
        return memo[idx][d] = ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n = jobDifficulty.size();
        memset(memo,-1,sizeof(memo));
        if(d>n){
            return -1;
        }
        return solve(jobDifficulty,d,0);
    }
};
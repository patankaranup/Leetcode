class Solution {
public:
    int n;
    int memo[1001][1001];
    int solve(int prev_idx,int curr_idx,vector<vector<int>>& pairs){
        if(curr_idx>=n){
            return 0;
        }
        if(prev_idx != -1 && memo[prev_idx][curr_idx] != -1){
            return memo[prev_idx][curr_idx];
        }
        int take_idx = 0;
        if(prev_idx == -1 || pairs[curr_idx][0]>pairs[prev_idx][1]){
            take_idx = 1 + solve(curr_idx,curr_idx+1,pairs);
        }
        int skip_idx = solve(prev_idx,curr_idx+1,pairs);
        if(prev_idx != -1){
            memo[prev_idx][curr_idx] = max(take_idx,skip_idx);
        }
        return max(take_idx,skip_idx);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        n = pairs.size();
        memset(memo,-1,sizeof(memo));
        sort(begin(pairs),end(pairs));
        return solve(-1,0,pairs);
    }
};
class Solution1 {
public:
    vector<vector<int>> dp;
    int n;
    int solve(int idx,int k,vector<vector<int>>& events){
        if(idx>=n || k == 0){
            return 0;
        }
        if(dp[idx][k] != -1){
            return dp[idx][k];
        }
        int start_day = events[idx][0];
        int end_day = events[idx][1];
        int val = events[idx][2];

        int skip_idx = solve(idx+1,k,events);

        // binary search to find new idx which is greater than current index last date 
        vector<int> temp = {end_day, INT_MAX, INT_MAX};
        int j = upper_bound(events.begin() + idx+1,events.end(),temp) - events.begin();

        int take_idx = val + solve(j,k-1,events);
        return dp[idx][k] = max(skip_idx,take_idx);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(begin(events),end(events));
        n = events.size();
        dp.resize(n+1,vector<int>(k+1,-1));
        return solve(0,k,events);
    }
};

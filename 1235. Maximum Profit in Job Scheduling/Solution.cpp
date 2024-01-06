class Solution {
public:
    int memo[50001];
    int n;
    int nextIdx(vector<vector<int>>& sortedTime, int left, int target) {
        int right = n-1;
        int idx = n;       
        while(left <= right) {
            int mid = left + (right-left)/2;
            if(sortedTime[mid][0] >= target) { 
                idx = mid;
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return idx;
    }
    int solve(vector<vector<int>>& sortedTime, int idx) {
        if(idx >= n) return 0;
        if(memo[idx] != -1) return memo[idx];

        int nextIndex  = nextIdx(sortedTime, idx+1, sortedTime[idx][1]);

        int take = sortedTime[idx][2] + solve(sortedTime, nextIndex);
        int skip = solve(sortedTime, idx+1);

        return memo[idx] = max(take, skip);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        memset(memo, -1, sizeof(memo));
        // for storing start end and profit 
        vector<vector<int>> sortedTime(n, vector<int>(3, 0)); 
        for(int idx = 0; idx<n; idx++) {
            sortedTime[idx][0] = startTime[idx];
            sortedTime[idx][1] = endTime[idx];
            sortedTime[idx][2] = profit[idx];
        } 
        auto lambda = [&](auto& vec1, auto& vec2) {
            return vec1[0] < vec2[0];
        };
        sort(begin(sortedTime), end(sortedTime), lambda);
        return solve(sortedTime, 0);
    }
};
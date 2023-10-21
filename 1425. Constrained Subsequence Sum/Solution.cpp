class Solution {
public:
    typedef pair<int,int> P;
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        priority_queue<P> pq;
        for(int i=0; i<n; i++){
            dp[i] = nums[i];
        }
        pq.push({dp[0],0});
        int result = dp[0];
        for(int i=1; i<n; i++){
            while(!pq.empty() && i - pq.top().second > k){
                pq.pop();
            }
            dp[i] = max(dp[i],nums[i]+pq.top().first);
            pq.push({dp[i],i});
            result = max(dp[i],result);
        }
        return result;
    }
};
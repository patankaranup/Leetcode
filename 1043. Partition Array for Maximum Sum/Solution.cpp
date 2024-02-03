class Solution {
public:
    int n;
    int solve(int idx, vector<int>& arr, int k, vector<int> &memo){
        if (idx>=n) return 0;
        if(memo[idx] != -1){
            return memo[idx];
        }
        int maxSum = INT_MIN;
        int currMaxElement = INT_MIN;
        int len = 0;
        for(int i=idx; i<min(n,idx+k); i++){
            len++;
            currMaxElement = max(currMaxElement,arr[i]);
            int sum = (currMaxElement*len) + solve(i+1,arr,k, memo);
            maxSum = max(sum, maxSum);
        }
        return memo[idx] = maxSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        vector<int> memo(n,-1);
        return solve(0,arr,k,memo);
    }
};
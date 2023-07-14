class Solution {
public:
    int memo[100001];
    int n;
    int cd;
    int solve(int idx, vector<int>& arr){
        if(memo[idx] != -1){
            return memo[idx];
        }
        int max_sequence = 0;
        for(int j = idx+1; j<n; j++){
            int prevVal = arr[idx];
            int newVal = arr[j];
            if(cd == newVal - prevVal){
                max_sequence = max(max_sequence, 1+solve(j,arr));
            }
        }
        return memo[idx] = max_sequence;

    }
    int longestSubsequence(vector<int>& arr, int difference) {
        n = arr.size();
        int result = 0;
        cd = difference;

        memset(memo,-1,sizeof(memo));

        for(int i=0; i<n; i++){
            result = max(result , 1 + solve(i, arr));
        }

        return result;
    }
};
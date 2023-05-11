class Solution {
public:
    int dp[501][501];
    int m , n;
    int recursion(vector<int>& nums1, vector<int>& nums2, int i, int j){
        if(i>=m || j>=n){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(nums1[i] == nums2[j]){
            return dp[i][j] = 1 + recursion(nums1,nums2,i+1,j+1);
        } else {
            return dp[i][j] = max(recursion(nums1,nums2,i+1,j),recursion(nums1,nums2,i,j+1));
        }

    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();
        memset(dp,-1,sizeof(dp));
        return recursion(nums1,nums2,0,0);
    }
};
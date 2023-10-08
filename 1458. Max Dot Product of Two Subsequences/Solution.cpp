class Solution {
public:
    int m,n;
    int memo[501][501];
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j){
        if(i == m || j == n){
            return -1e9;
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        int curr_prod_of_i_and_j = nums1[i] * nums2[j];
        int take_i_j_and_go_further = curr_prod_of_i_and_j + solve(nums1,nums2,i+1,j+1);
        int take_i_and_go_further = solve(nums1,nums2,i,j+1);
        int take_j_and_go_further = solve(nums1,nums2,i+1,j);
        return memo[i][j] = max({curr_prod_of_i_and_j,take_i_j_and_go_further,take_i_and_go_further,take_j_and_go_further});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();
        memset(memo,-1,sizeof(memo));
        return solve(nums1,nums2,0,0); 
    }
};
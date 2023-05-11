class Solution1 {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
       int m = nums1.size();
       int n = nums2.size();
       vector<vector<int>> vec(m+1,vector<int>(n+1));
        // filling row 0 and col 0 to 0
        for(int i=0; i<m+1; i++){
            for(int j=0; j<n+1; j++){
                if(i==0 || j==0){
                    vec[i][j] = 0;
                } else if(nums1[i-1] == nums2[j-1]){
                    vec[i][j] = 1 + vec[i-1][j-1];
                } else{
                    vec[i][j] = max(vec[i][j-1],vec[i-1][j]);
                }
            }
        }
        return vec[m][n];
    }
};
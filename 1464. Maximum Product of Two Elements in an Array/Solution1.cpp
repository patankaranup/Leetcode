class Solution1 {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int maxi = nums[0];
        for(int i=1; i<n; i++){
            res = max(res, (maxi-1)*(nums[i]-1));
            maxi = max(maxi,nums[i]);
        }
        return res;
    }
};
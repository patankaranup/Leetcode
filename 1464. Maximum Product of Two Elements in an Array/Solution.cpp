class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums),end(nums));
        int a = nums[n-1]-1;
        int b = nums[n-2]-1;
        return a*b;
    }
};
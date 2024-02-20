class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ts = n*(n+1)/2;
        for(int i=0; i<n; i++){
            ts -= nums[i];
        }
        return ts;
    }
};
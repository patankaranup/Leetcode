class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n-1;
        int maxSum = 0;
        sort(begin(nums),end(nums));
        while(i<j){
            int sum = nums[i] + nums[j];
            maxSum = max(maxSum,sum);
            i++;
            j--;
        }
        return maxSum;
    }
};
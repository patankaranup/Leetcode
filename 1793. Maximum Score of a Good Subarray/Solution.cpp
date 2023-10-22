class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int i=k;
        int j=k;
        int currMin = nums[k];
        int result = nums[k];

        while(i>0 || j<n-1){
            int lv = (i>0) ? nums[i-1] : 0;
            int rv = (j<n-1) ? nums[j+1] : 0;
            if(lv < rv){
                j++;
                currMin = min(nums[j], currMin);
            } else {
                i--;
                currMin = min(nums[i], currMin);
            }
            result = max(result, currMin*(j-i+1));
        }
        return result;
    }
};
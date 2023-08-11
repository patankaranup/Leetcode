class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int n = nums.size();

        int minKPosition = -1;
        int maxKPosition = -1;
        int culpritIdx = -1;

        for(int i=0; i<n; i++){
            if(nums[i] < minK || nums[i] > maxK){
                culpritIdx = i;
            }
            if(nums[i] == minK){
                minKPosition = i;
            }
            if(nums[i] == maxK){
                maxKPosition = i;
            }

            long long smallerIdx = min(minKPosition,maxKPosition);
            long long temp = smallerIdx - culpritIdx;

            ans += (temp <= 0) ? 0 : temp;

        }
        return ans;

    }
};
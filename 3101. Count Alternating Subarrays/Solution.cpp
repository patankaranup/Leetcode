class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long n = nums.size();
        long long result = 0;
        for(int i=0; i<n; i++){
            long long j = i;
            while(j+1 < n && nums[j] != nums[j+1]){ 
                // go ahead till we are getting alternating subarrays 
                j++;
            }
            long long len = j-i+1;
            result += (len * (len+1)/2);
            i = j;
        }
        return result;
    }
};
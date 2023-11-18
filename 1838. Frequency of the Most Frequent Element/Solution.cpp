class Solution {
public:
    typedef long long ll;
    ll binearySearch(int target_idx, int k, vector<int>& nums, vector<ll>& prefixSum){
        int target_element = nums[target_idx];
        int l = 0;
        int r = target_idx;
        int idx = -1;
        while(l<=r){
            ll mid = l + (r-l)/2;
            ll count = target_idx - mid + 1;
            ll currSum =  count * target_element;
            ll originalSum = prefixSum[target_idx] - prefixSum[mid] + nums[mid];
            ll ops = currSum - originalSum;
            if(ops>k){
                l = mid+1;
            } else {
                idx = mid;
                r = mid - 1;
            }
        }
        return target_idx - idx + 1;
    }
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums),end(nums));

        // Prefix sum 
        vector<ll> prefixSum(n);
        prefixSum[0] = nums[0];
        for(int i=1; i<n; i++){
            prefixSum[i] = nums[i] + prefixSum[i-1];
        }
        int result = 0;

        for(int target_idx = 0; target_idx < n; target_idx++){
            int currMax = binearySearch(target_idx,k,nums,prefixSum);
            result = max(result,currMax);
        }
        return result;
    }
};
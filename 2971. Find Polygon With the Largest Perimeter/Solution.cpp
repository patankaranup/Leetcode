class Solution {
public:
    typedef long long ll;
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        ll ans = 0;
        vector<ll> pSum(n);
        pSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pSum[i] = pSum[i - 1] + nums[i];
        }
        for (int i = 2; i < n; i++) {
            if (nums[i] < pSum[i - 1]) {
                ans = max(ans, pSum[i]);
            }
        }
        return ans == 0 ? -1 : ans;
    }
};

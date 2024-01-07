class Solution {
public:
    typedef long long ll;
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        ll ans = 0;
        // making array of map 
        unordered_map<ll,ll> mp[n];

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                // j is starting from 0 to i 
                ll common_diff = (ll)nums[i] - nums[j];

                auto iter = mp[j].find(common_diff);
                // number of counts a j for the common difference 
                ll count_at_j = (iter == end(mp[j])) ? 0 : iter->second;
                // adding the previous cnt and the new one 
                mp[i][common_diff] += count_at_j + 1;
                ans += count_at_j;
            }
        }
        return ans;
    }
};
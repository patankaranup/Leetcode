class Solution {
public:
    int M = 1e9+7;
    int rev(int num){
        int ans = 0;
        while(num){
            int l_digit = num%10;
            ans = (ans * 10) + l_digit;
            num /= 10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            nums[i] = nums[i] - rev(nums[i]);
        }
        int pairs = 0;
        for(int i=0; i<n; i++){
            pairs = (pairs + mp[nums[i]]) % M;
            mp[nums[i]]++;
        }
        return pairs;
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> vec(n+1,0);
        // vec[i] = maximum stolen money till ith house
        vec[0] = 0; // no house no money 
        vec[1] = nums[0]; // first house money if stolen

        for(int i = 2; i<=n; i++){
            int currHouseMoney = nums[i-1];
            // if we steal house we have to include the current House money and add the previous 2nd adjacent money
            // if we skip this house we can take the money from previous house
            int stealHouse = currHouseMoney + vec[i-2];
            int skipHouse = vec[i-1];
            // take the maximum money we can have from both options 
            vec[i] = max(stealHouse,skipHouse);
        }
        return vec[n];
    }
};
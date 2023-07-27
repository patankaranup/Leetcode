class Solution2 {
public:

    int solve(int l,int r,vector<int>& nums){

        int prev_prev = 0;
        int prev = 0;

        for(int i=l; i<=r; i++){
            int currHouseMoney = nums[i];
            int robHouse = currHouseMoney + prev_prev;
            int skipHouse = prev;
            int maxProfit = max(robHouse,skipHouse);
            prev_prev = prev;
            prev = maxProfit;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]);
        }

        // Case 1 : we took money from 1st house so no last house is allowed
        int money_from_1st_case = solve(0,n-2,nums);

        // Case 2 : we took money from 2nd house so we can take last house
        int money_from_2nd_case = solve(1,n-1,nums);


        return max(money_from_1st_case,money_from_2nd_case);
    }
};
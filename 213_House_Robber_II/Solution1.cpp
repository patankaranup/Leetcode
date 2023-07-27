class Solution1 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        // money[i] is maximum money we got after robbing ith house
        vector<int> money(n+1,0); 

        // Case 1 : we took money from 1st house so no last house is allowed
        money[0] = 0; // no house no money

        for(int i=1; i<=n-1; i++){
            // we can get 2nd last money and this one 
            int rob_house = nums[i-1] + ((i-2 >= 0) ? money[i-2] : 0);
            // if we skip house we can get money of previous house
            int skip_house = money[i-1];
            money[i] = max(rob_house,skip_house);
        }
        int money_from_1st_case = money[n-1];
        money.clear();

        // Case 2 : we took money from 2nd house so we can take last house

        money[0] = 0; // no house no money
        money[1] = 0; // since we skip 1st house

        for(int i=2; i<=n; i++){

            int rob_house = nums[i-1] + ((i-2 >= 0) ? money[i-2] : 0);
            int skip_house = money[i-1];

            money[i] = max(rob_house,skip_house);
        }
        int money_from_2nd_case = money[n];


        return max(money_from_1st_case,money_from_2nd_case);
    }
};
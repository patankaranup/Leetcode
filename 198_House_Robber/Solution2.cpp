class Solution2 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n==1){
            return nums[0];
        }

        int prev_prev = 0; // no house no money 
        int prev = nums[0]; // first house money if stolen

        for(int i = 2; i<=n; i++){
            int currHouseMoney = nums[i-1];

            int stealHouse = currHouseMoney + prev_prev;
            int skipHouse = prev;
            
            int temp = max(stealHouse,skipHouse);

            prev_prev = prev;
            prev = temp;

        }
        return prev;
    }
};
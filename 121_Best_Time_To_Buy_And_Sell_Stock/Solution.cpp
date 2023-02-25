class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 1;
        int maxProfit = 0;
        while(right < prices.size()){
            if(prices[left]>prices[right]){
                left = right;
            } else {
                int currentProfit = prices[right]-prices[left];
                maxProfit = max(currentProfit,maxProfit);
                right+=1;
            }
        }
        return maxProfit;
    }
};


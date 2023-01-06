class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(begin(costs), end(costs)); // sorts in ascending order
        int count = 0;
        for (int &cost : costs){
            if (cost>coins){
                return count;
            } else{
                count+=1;
                coins = coins-cost;
            }
        }
        return count;

    }
};

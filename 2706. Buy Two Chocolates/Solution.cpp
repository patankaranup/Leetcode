class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int minElem       = INT_MAX;
        int secondMinElem = INT_MAX;
        for(auto &price : prices){
            if(price<minElem){
                secondMinElem = minElem;
                minElem       = price;
            } else if(price<secondMinElem){
                secondMinElem = price;
            }
        }
        int sum = minElem + secondMinElem;
        if(sum <= money){
            return money-sum;
        }
        return money;
    }
};